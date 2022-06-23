#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char *get_next_line(int fd);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_substr(char const *s, unsigned int start);

#endif