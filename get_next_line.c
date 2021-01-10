//#include "get_next_line.h"
int BUFFER_SIZE 32;

int		get_next_line(int fd, char **line)
{
	static	fd_buffer[1024]={0};
	char	*read_buffer;

	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(read_buffer) || fd < 0 || )
}
