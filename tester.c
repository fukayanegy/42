# include "get_next_line.h"
# include <stdio.h>

int	main(void)
{
    int fd;
    char *buffer;
    ssize_t bytes_read;

buffer = malloc(1024);
    // ファイルをオープンします
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

	while (buffer)
	{
		buffer = get_next_line(fd);
		printf("%s\n", buffer);
		free(buffer);
	}

    // ファイルからデータを読み込み、標準出力に出力します
    // while ((bytes_read = read(fd, buffer, 1024)) > 0) {
    //     write(STDOUT_FILENO, buffer, bytes_read);
    // }

    // ファイルをクローズします
    close(fd);

	// char	s1[] = "abcdef\nhogehoge";
	// char	s2[] = "ghijklm";
	// char	*result_before;
	// char	*result_after;

	// printf("start\n");
	// result_before = ft_copy_newline_before(s1);
	// printf("-------------\n");
	// printf("%s\n", result_before);
	// printf("-------------\n");
	// result_after = ft_copy_newline_after(s1);
	// printf("-------------\n");
	// printf("%s\n", result_after);
	// printf("-------------\n");
	// printf("start\n");
	// // result = ft_strjoin(NULL, NULL);
	// // printf("result is %s\n", result);
	// printf("s1 len is %zu\n", ft_strlen(s1));
	// printf("s2 len is %zu\n", ft_strlen(s2));
	// result = ft_strchr(s1, '\n');
	// printf("result is %s\n", result);

	return (0);
}
