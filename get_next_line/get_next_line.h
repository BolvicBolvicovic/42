#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char    *get_next_line(int fd);
char	*ft_strchr(char *s, int c);
int	ft_strlen(const char *str);
char    *ft_strdup(char *src);
char    *ft_strjoin(char *s1, char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
