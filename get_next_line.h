#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE
#ifndef BUFFA_SIZE
#define BUFFA_SIZE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
bool	ft_is_include_newline(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_copy_newline_before(char *read_data);
char	*ft_copy_newline_after(char *read_data);
char	*ft_read(int fd, char *read_data, bool *is_finish);
char	*get_next_line(int fd);

#endif
