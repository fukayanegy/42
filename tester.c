#include "get_next_line.h"
# include <stdio.h>
# include <libc.h>
# define TEST_PATH "test_text/test_00"

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open(TEST_PATH, O_RDONLY);
	for(int i = 0; line != NULL; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	free(line);
	return (0);
}

/* 
int	main(void)
{
	char	original_s[] = "abcdefghij\n123456";
	char	*copy_s;
	int		return_value;

	copy_s = NULL;
	return_value = ft_copy_newline_before_test(original_s, copy_s);
	printf("%d\n", return_value);
	printf("%s\n", copy_s);
	return (0);
}
 */