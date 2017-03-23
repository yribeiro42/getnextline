#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		printf(GRN "%s\n" RESET, line);
	return (0);
}
