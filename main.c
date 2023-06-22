/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:12:52 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/22 16:03:27 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

# define TEST_PATH "test_1.txt"

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open(TEST_PATH, O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}
