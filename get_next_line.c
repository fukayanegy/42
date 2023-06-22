/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:07:57 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/22 19:32:00 by etakaham         ###   ########.fr       */
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

	// 出力する文字を入れるresを定義し、read()が使用できなければ、return を返す
	res = NULL;
	if (read(fd, res, 0) == -1)
		return (NULL);
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));

	// read した文字を入れる read_dataを定義する
	temporary_read_data = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temporary_read_data == NULL)
		return (NULL);

	read_data = NULL;
	// while 文でread_dataの中に改行文字が含まれるまでreadを繰り返す
	while (true)
	{
		// BUFFA_SIZEまで読み取る
		read(fd, temporary_read_data, BUFFER_SIZE);
		// read_data を \n の前の文字列と後ろの文字列に分ける
		read_data = ft_strjoin(read_data, temporary_read_data);
		res = ft_search_newline(read_data);
		// read_data を \n の前の文字列と後ろの文字列に分ける
		if (res != NULL)
		{
			break ;
		}
	}
	// 前の文字列をresに、後ろの文字列をread_dataに格納する
	// このときに使用する'\n'で分ける関数を作成する
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