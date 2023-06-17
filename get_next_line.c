/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:07:57 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/17 21:42:26 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*res;
	static char	*read_data;

	if (read(fd, res, 0) == -1)
		return (NULL);
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_data = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_data == NULL)
		return (NULL);
	read(fd, read_data, BUFFER_SIZE);
	// read_data を \n の前の文字列と後ろの文字列に分ける
	// 前の文字列をresに、後ろの文字列をread_dataに格納する
	// このときに使用する'\n'で分ける関数を作成する
	return (read_data);
}
