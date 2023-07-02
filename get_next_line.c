#include "get_next_line.h"
#define BUFFA_SIZE 100

char	*get_next_line(int fd)
{
	char		*result;
	// read_data を配列にして配列の要素数をfdの整数値と見立てる
	// そうするとボーナスができるようになる
	static char	*read_data;

	if (fd < 0 || BUFFA_SIZE <= 0)
		return (NULL);
	read_data = ft_read(fd, read_data);
	if (read_data == NULL)
	{
		free(read_data);
		return (NULL);
	}
	result = ft_copy_newline_before(read_data);
	read_data = ft_copy_newline_after(read_data);
	return (result);
}

char	*ft_read(int fd, char *read_data)
{
	char	*temporary_read_data;
	ssize_t	read_size;

	temporary_read_data = malloc(sizeof(char) * (BUFFA_SIZE + 1));
	if (temporary_read_data == NULL)
		return (NULL);
	read_size = 1;
	while (!ft_is_include_newline(read_data) && read_size != 0)
	{
		read_size = read(fd, temporary_read_data, BUFFA_SIZE);
		if (read_size == -1)
		{
			free(temporary_read_data);
			return (NULL);
		}
		temporary_read_data[read_size] = '\0';
		read_data = ft_strjoin(read_data, temporary_read_data);
		if (read_data == NULL)
		{
			free(temporary_read_data);
			return (NULL);
		}
	}
	free(temporary_read_data);
	return (read_data);
}

char	*ft_copy_newline_before(char *read_data)
{
	ssize_t	i;
	char	*result;

	i = 0;
	if (read_data[i] == '\0')
		return (NULL);
	while (read_data[i] != '\0' && read_data[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (read_data[i] != '\0' && read_data[i] != '\n')
	{
		result[i] = read_data[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_copy_newline_after(char *read_data)
{
	ssize_t	i;
	ssize_t	j;
	char	*result;

	i = 0;
	while (read_data[i] != '\0' && read_data[i] != '\n')
		i++;
	if (read_data[i] == '\0')
	{
		free(read_data);
		return (NULL);
	}
	result = malloc(sizeof(char) * (ft_strlen(read_data) - i + 1));
	if (result == NULL)
		return (NULL);
	i++;
	j = 0;
	while (read_data[i] != '\0')
	{
		result[j++] = read_data[i++];
	}
	result[j] = '\0';
	return (result);
}
