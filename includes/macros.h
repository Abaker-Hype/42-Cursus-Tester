#ifndef MACROS_H
# define MACROS_H

# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>

# define malloc(X) malloc_track(X, __FILE__, __LINE__, __FUNCTION__)
# define free(X) free_track(X, true)

extern int BUFFER_SIZE;

void	*malloc_track(size_t size, const char *file, int line, const char *func);
void	free_track(void *p, bool check);
ssize_t	write(int fd, const void *buff, size_t nbyte);	

#endif
