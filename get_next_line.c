/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:11:13 by etakaham          #+#    #+#             */
/*   Updated: 2023/07/02 17:48:50 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*result;
	char		*tmp;
	static char	*read_data;
	bool		is_finish;

	is_finish = false;
	if (fd < 0 || BUFFA_SIZE <= 0)
		return (NULL);
	read_data = ft_read(fd, read_data, &is_finish);
	if (read_data == NULL)
		return (NULL);
	result = ft_copy_newline_before(read_data);
	tmp = read_data;
	read_data = ft_copy_newline_after(read_data);
	free(tmp);
	if (is_finish)
	{
		free(read_data);
		read_data = NULL;
	}
	return (result);
}

char	*ft_read(int fd, char *read_data, bool *is_finish)
{
	char	*tmp_read_data;
	char	*tmp;
	ssize_t	read_size;

	tmp_read_data = malloc(sizeof(char) * (BUFFA_SIZE + 1));
	if (tmp_read_data == NULL)
		return (NULL);
	read_size = 1;
	while (!ft_is_include_newline(read_data) && read_size > 0)
	{
		read_size = read(fd, tmp_read_data, BUFFA_SIZE);
		if (read_size <= 0)
		{
			free(tmp_read_data);
			if (read_size == 0)
				return (read_data);
			else
				return (NULL);
		}
		tmp_read_data[read_size] = '\0';
		tmp = read_data;
		read_data = ft_strjoin(read_data, tmp_read_data);
		free(tmp);
		if (read_data == NULL)
		{
			free(tmp_read_data);
			return (NULL);
		}
	}
	if (read_size == 0)
		*is_finish = true;
	free(tmp_read_data);
	return (read_data);
}
