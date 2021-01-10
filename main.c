#include "get_next_line.h"

int get_next_line(int fd, char **line); 

int		main(void)
{
	int fd;
	char *line;

	fd = open("./test.txt", O_WRONLY);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}