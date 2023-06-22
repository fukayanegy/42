/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:08:02 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/22 16:08:59 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_search_newline(char *s)
{
	char	*newline;
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			newline = malloc(sizeof(char) * (i + 1));
			j = 0;
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

static void	ft_strjoin_support(char const *s1, char const *s2, char *res)
{
	size_t	i;
	size_t	s_1_len;
	size_t	s_2_len;

	s_1_len = ft_strlen(s1);
	s_2_len = ft_strlen(s2);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[s_1_len + i] = s2[i];
		i++;
	}
	res[s_1_len + s_2_len] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_1_len;
	size_t	s_2_len;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s_1_len = ft_strlen(s1);
	s_2_len = ft_strlen(s2);
	res = malloc((sizeof(char)) * (s_1_len + s_2_len + 1));
	if (res == NULL)
		return (NULL);
	ft_strjoin_support(s1, s2, res);
	return (res);
}
