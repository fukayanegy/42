#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_copy_newline_after(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_copy_newline_before(const char *s);
bool	ft_exist_newline(const char *s);

int	ft_copy_newline_before_test(const char *original_s, char *copy_s);
#endif