#include "tester.h"

typedef struct	s_malloc{
	void			*p;
	const char		*file;
	int				line;
	const char		*func;
	size_t			size;
	bool			freed;
	struct s_malloc	*next;
}	t_malloc;

static t_malloc *leaks = NULL;
char *LEAK = "Malloc in File: %s on line: %i in Func: %s has leaked a total of %i times!\n";

static t_malloc *newnode(void *p, const char *file, int line, const char *func, size_t size)
{
	t_malloc *new; 
	new = malloc(sizeof(t_malloc));
	new->p = p;
	new->file = file;
	new->line = line;
	new->func = func;
	new->size = size;
	new->freed = false;
	new->next = NULL;
	return (new);
}

static void	addnode(t_malloc *new)
{
	if (!leaks) leaks = new;
	else {
		t_malloc *curr = leaks;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

static t_malloc *findnode(void *ptr)
{
	t_malloc *curr = leaks;
	while (curr){
		if (curr->p == ptr) break;
		curr = curr->next;
	}
	return (curr);
}

static bool	freeptr(void *ptr)
{
	t_malloc *node = findnode(ptr);
	if (!node) return (false);
	free(node->p);
	node->freed = true;
	return (true);
}

static bool comparemalloc(t_malloc *m1, t_malloc *m2)
{
	return (m1->line == m2->line && strcmp(m1->file, m2->file) == 0 && strcmp(m1->func, m2->func) == 0);
}

static bool isunique(t_malloc *search)
{
	t_malloc *curr = leaks;
	while (curr){
		if (curr == search) break;
		if (comparemalloc(curr, search)) return (false);
		curr = curr->next;
	}
	return (true);
}

static int	counttimes(t_malloc *start)
{
	int i = 0;
	t_malloc *curr = start;
	while (curr){
		if (!curr->freed && comparemalloc(curr, start)) i++;
		curr = curr->next;
	}
	return (i);
}

void	*malloc_track(size_t size, const char *file, int line, const char *func)
{
	void *p = malloc(size);
	addnode(newnode(p, file, line, func, size));
	return (p);
}

void	free_track(void *p)
{
	if (!freeptr(p)) free(p);
}

bool	hasleaks()
{
	t_malloc *curr = leaks;
	while (curr){
		if (!curr->freed) return (true);
		curr = curr->next;
	}
	return (false);
}

void	freeleaks()
{
	t_malloc *curr = leaks, *next = NULL;
	while (curr){
		if (!curr->freed) free(curr->p);
		curr = curr->next;
		free(curr);
		curr = next;
	}
}

void	listleaks()
{
	t_malloc *curr = leaks;
	while (curr){
		if (!curr->freed && isunique(curr)){
			cprintf(LEAK, YELLOW, DEFAULT, curr->file, curr->line, curr->func, counttimes(curr));
		}
		curr = curr->next;
	}
}
