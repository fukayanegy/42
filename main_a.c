/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:50:18 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/22 16:27:05 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	s[] = "abcde\nfgdh";
	char	t[] = "abcdefgdh";
	char	*res_1;
	res_1 = ft_search_newline(s);
	printf("%s\n", res_1);
	printf("%s\n", s);
	// printf("%s\n", res_2);
	return (0);
}
