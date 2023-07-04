/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:16:03 by etakaham          #+#    #+#             */
/*   Updated: 2023/07/02 17:16:04 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

bool	ft_is_include_newline(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (s1 == NULL)
		return (ft_strjoin("", s2));
	if (s2 == NULL)
		return (ft_strjoin(s1, ""));
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
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
	if (read_data[i] == '\n')
	{
		result[i] = '\n';
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
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(read_data) - i + 1));
	if (result == NULL)
		return (NULL);
	i++;
	j = 0;
	while (read_data[i] != '\0')
		result[j++] = read_data[i++];
	result[j] = '\0';
	return (result);
}
