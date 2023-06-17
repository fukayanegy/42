/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:07:57 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/17 21:38:32 by etakaham         ###   ########.fr       */
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
	return (read_data);
}
