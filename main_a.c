/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:50:18 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/22 16:03:00 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	s[] = "abcdefgdh";
	char	t[] = "abcdefgdh";
	size_t len = ft_strlen(s);
	char	*res_1 = ft_search_newline(s);
	char	*res_2 = ft_strjoin(s, t);
	printf("%zu\n", len);
	printf("%s\n", res_1);
	printf("%s\n", res_2);
	return (0);
}