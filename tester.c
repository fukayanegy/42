# include "get_next_line.h"
# include <stdio.h>

int	main(void)
{
	int		fd;
	char	*buffer;

	buffer = malloc(1024);
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		return 1;
	}
	while (buffer)
	{
		buffer = get_next_line(fd);
		printf("%s", buffer);
		free(buffer);
	}
	close(fd);
	return (0);
}
