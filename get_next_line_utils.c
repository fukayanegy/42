/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:07:11 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/24 19:42:10 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_skip_newline(const char *s)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	result = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (result == NULL)
		return (NULL);
	j = 0;
	i++;
	while (i < ft_strlen(s))
		result[j++] = s[i++];
	result[j] = '\0';
	return (result);
}

char	*ft_search_newline(char *s)
{
	char	*newline;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
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
	size_t		s_1_len;
	size_t		s_2_len;
	char		*res;
	const char	*empty_str = "";

	if (s1 == NULL && s2 != NULL)
		return (ft_strjoin(s2, empty_str));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strjoin(s1, empty_str));
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	s_1_len = ft_strlen(s1);
	s_2_len = ft_strlen(s2);
	res = malloc((sizeof(char)) * (s_1_len + s_2_len + 1));
	if (res == NULL)
		return (NULL);
	ft_strjoin_support(s1, s2, res);
	return (res);
}
