/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:08:02 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/17 21:18:47 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_search_newline(char *s)
{
	char	*newline;
	size_t	i;
	size_t	j;

	while (s[i] == '\0')
	{
		if (s[i] == '\n')
		{
			newline = malloc(sizeof(char) * (i + 1));
			while (j < i)
			{
				newline[j] = s[j];
				j++;
			}
			newline[j] = '\0';
			return (newline);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		result[s1_len + i] = s2[i];
		i++;
	}
	result[s1_len + s2_len] = '\0';
	return (result);
}
