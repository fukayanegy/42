/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:50:18 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/24 14:10:27 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdio.h>

int	main(void)
{
	char	*s = "abcde\nfgdh";
	char	t[] = "abcdefgdh";
	s = ft_skip_newline(s);
	printf("%s\n", s);
	return (0);
}
