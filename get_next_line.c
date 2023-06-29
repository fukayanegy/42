#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*res;
	char		*temporary_read_data;
	static char	*read_data;
	ssize_t		read_size;
	int			checker;

	checker = 0;
	if (BUFFER_SIZE < 1)
		return (NULL);
	res = NULL;
	if (read(fd, res, 0) == -1)
		return (NULL);
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	temporary_read_data = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (res == NULL || temporary_read_data == NULL)
		return (NULL);

	read_data = ft_copy_newline_after(read_data);
	if (read_data == NULL)
	{
		free(temporary_read_data);
		free(res);
		return (NULL);
	}
	while (!ft_exist_newline(read_data))
	{
		read_size = read(fd, temporary_read_data, BUFFER_SIZE);
		if (read_size <= 0)
		{
			return (NULL);
		}
		temporary_read_data[read_size] = '\0';
		read_data = ft_strjoin(read_data, temporary_read_data);
		if (read_data == NULL)
		{
			free(read_data);
			free(temporary_read_data);
			free(res);
			return (NULL);
		}
	}
	res = ft_copy_newline_before(read_data);
	if (res == NULL)
	{
		free(read_data);
		free(temporary_read_data);
		free(res);
		return (NULL);
	}
	free(temporary_read_data);
	return (res);
}
