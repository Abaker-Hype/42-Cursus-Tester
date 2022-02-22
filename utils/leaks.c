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
	t_malloc *node = leaks, *prev = NULL;
	if (!node) return (false);
	while (node && node->p != ptr){
		prev = node;
		node = node->next;
	}
	if (node->p == ptr){
		if (prev)
			prev->next = node->next;
		else
			leaks = node->next;
		free(ptr);
		free(node);
		return (true);
	}
	return (false);
}

static bool comparemalloc(t_malloc *m1, t_malloc *m2)
{
	return (m1->line == m2->line && strcmp(m1->file, m2->file) == 0 && strcmp(m1->func, m2->func) == 0);
}

static bool isunique(t_malloc *search)
{
	t_malloc *curr = leaks;
	while (curr){
		if (curr == search) return (true);
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
		if (comparemalloc(curr, start)) i++;
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

void	free_track(void *p, bool check)
{
	if (!check) free(p);
	else if (!freeptr(p) && args.detail) cprintf("ERROR! Tried to Free pointer which wasn't Malloced\n",RED, DEFAULT);
}

bool	hasleaks()
{
	return (leaks != NULL);
}

void	freeleaks()
{
	t_malloc *curr = leaks, *next = NULL;
	while (curr){
		next = curr->next;
		free(curr->p);
		free(curr);
		curr = next;
	}
	leaks = NULL;
}

void	listleaks()
{
	t_malloc *curr = leaks;
	while (curr){
		if (isunique(curr))
			cprintf(LEAK, YELLOW, DEFAULT, curr->file, curr->line, curr->func, counttimes(curr));
		curr = curr->next;
	}
	freeleaks();
}
