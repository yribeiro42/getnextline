#include "get_next_line.h"
#include <stdio.h>

int				main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	write(fd, "ghijklmnopqrstuv\n", 17);
	write(fd, "wxyzabcdefghijkl\n", 17);
	write(fd, "mnopqrstuvwxyzab\n", 17);
	write(fd, "cdefghijklmnopqr\n", 17);
	write(fd, "stuvwxzabcdefghi\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	if (strcmp(line, "abcdefghijklmnop") == 0)
		printf("OK\n");
	get_next_line(p[0], &line);
	if (strcmp(line, "qrstuvwxyzabcdef") == 0)
		printf("OK\n");
	get_next_line(p[0], &line);
	if (strcmp(line, "ghijklmnopqrstuv") == 0)
		printf("OK\n");
	get_next_line(p[0], &line);
	if (strcmp(line, "wxyzabcdefghijkl") == 0)
		printf("OK\n");
	get_next_line(p[0], &line);
	if (strcmp(line, "mnopqrstuvwxyzab") == 0)
		printf("OK\n");
	get_next_line(p[0], &line);
	if (strcmp(line, "cdefghijklmnopqr") == 0)
		printf("OK\n");
	get_next_line(p[0], &line);
	if (strcmp(line, "stuvwxzabcdefghi") == 0)
		printf("OK\n");
	ret = get_next_line(p[0], &line);
	printf("ret = %d\n", ret);
}