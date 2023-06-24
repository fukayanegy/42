/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <kakigoori00007@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:12:52 by etakaham          #+#    #+#             */
/*   Updated: 2023/06/24 13:00:37 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define TEST_PATH "test_2.txt"

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open(TEST_PATH, O_RDONLY);
	for(int i = 0; i < 15; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	free(line);
	return (0);
}
