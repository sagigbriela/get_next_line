#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*free_buffer(char *new_line, char *buf);
char	*clean_line(char *new_line);
char	*next_line(char *new_line);
char	*read_line(int fd, char *new_line);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr_mod(char *s, int c);

#endif