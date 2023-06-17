/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:07:57 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/17 20:54:51 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*res;

	if (read(fd, res, 0) == -1)
		return (NULL);
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (res == NULL)
		return (NULL);
	if (read(fd, res, BUFFER_SIZE) <= 0)
	{
		free(res);
		return (NULL);
	}
	if (ft_search_newline(res) == 1)
		return (res);
}
