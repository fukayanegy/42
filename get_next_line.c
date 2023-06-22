/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:07:57 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/22 20:37:48 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

# define TEST_PATH "test_1.txt"
char	*get_next_line(int fd)
{
	char		*res;
	char		*temporary_read_data;
	static char	*read_data;

	res = NULL;
	if (read(fd, res, 0) == -1)
		return (NULL);
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	temporary_read_data = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temporary_read_data == NULL)
		return (NULL);
	// この文字列を改行以降のものに変えれば良い
	// 今回では１にすれば良い
	read_data = "1";
	while (true)
	{
		read(fd, temporary_read_data, BUFFER_SIZE);
		printf("before setting, %s\n", read_data);
		read_data = ft_strjoin(read_data, temporary_read_data);
		printf("after setting, %s\n", read_data);
		res = ft_search_newline(read_data);
		if (res != NULL)
			break ;
	}
	return (res);
}

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open(TEST_PATH, O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}