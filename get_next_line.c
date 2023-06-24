/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:07:57 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/24 14:40:46 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	char		*temporary_read_data;
	static char	*read_data;
	ssize_t		read_size;

	if (BUFFER_SIZE < 1)
		return (NULL);
	res = NULL;
	if (read(fd, res, 0) == -1)
		return (NULL);
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	temporary_read_data = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temporary_read_data == NULL)
		return (NULL);
	read_data = ft_skip_newline(read_data);
	while (true)
	{
		read_size = read(fd, temporary_read_data, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		temporary_read_data[read_size] = '\0';
		read_data = ft_strjoin(read_data, temporary_read_data);
	}
	res = ft_search_newline(read_data);
	return (res);
}
