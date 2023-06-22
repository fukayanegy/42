/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:50:18 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/22 20:43:47 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*s = "abcde\nfgdh";
	char	t[] = "abcdefgdh";
	char	*res_1;
	s = ft_skip_newline(s);
	printf("%s\n", res_1);
	return (0);
}
