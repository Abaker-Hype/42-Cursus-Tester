#include "tester.h"

typedef struct	s_malloc{
	void			*p;
	const char		*file;
	int				line;
	const char		*func;
	size_t			size;
	struct s_malloc	*next;
}	t_malloc;

static t_malloc *leaks = NULL;

static t_malloc *newnode(void *p, const char *file, int line, const char *func, size_t size)
{
	t_malloc *new; 
	new = malloc(sizeof(t_malloc));
	new->p = p;
	new->file = file;
	new->line = line;
	new->func = func;
	new->size = size;
	new->next = NULL;
	return (new);
}

static void	addlist(t_malloc *new)
{
	t_malloc *curr = leaks;
	if (!leaks)
		leaks = new;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

static void	removelist(void *p)
{
	if (!leaks)
		return ;
	t_malloc *curr, *prev = NULL;
	curr = leaks;
	while (curr)
	{
		if (curr->p == p)
		{
			if (!prev)
				leaks = curr->next;
			else
				prev->next = curr->next;
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

static void	clearlist()
{
	if (!leaks)
		return ;
	t_malloc *curr, *next = NULL;
	curr = leaks;
	while (curr)
	{
		next = curr->next;
		free(curr->p);
		free(curr);
		curr = next;
	}
}

static bool	isunique(t_malloc *chk)
{
	t_malloc *curr = leaks;
	while (curr)
	{
		if (curr == chk)
			break ;
		if (curr->line == chk->line && curr->file == chk->file && curr->func == chk->func)
			return (false);
		curr = curr->next;
	}
	return (true);
}

void	*malloc_track(size_t size, const char *file, int line, const char *func)
{
	void *p = malloc(size);
	addlist(newnode(p, file, line, func, size));
	return (p);
}

void	free_track(void *p)
{
	free(p);
	removelist(p);
}

bool	hasleaks()
{
	return (leaks != NULL);
}

void	freeleaks()
{
	clearlist();
	leaks = NULL;
}

void	listleaks(bool unique)
{
	t_malloc *curr = leaks;
	while(curr)
	{
		if (unique)
		{
			if (isunique(curr))
				printf("Malloc in File: %s on Line: %i in Func: %s is leaking\n", curr->file, curr->line, curr->func);
		} else
			printf("Malloc with addr: %p[%li] created in File: %s on Line: %i in Func: %s wasn't Freed\n", curr->p, curr->size, curr->file, curr->line, curr->func);
		curr = curr->next;
	}
}
