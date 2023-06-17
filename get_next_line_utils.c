/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:08:02 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/17 20:53:17 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search_newline(char *s)
{
	char	*newline;
	size_t	i;

	while (s[i] == '\0')
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			return (1);
		}
	}
	return (0);
}
