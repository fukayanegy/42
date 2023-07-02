#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_copy_newline_before(char *read_data);
char	*ft_copy_newline_after(char *read_data);
char	*ft_read(int fd, char *read_data);
char	*get_next_line(int fd);

#endif
