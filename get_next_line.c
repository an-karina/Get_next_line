//#include "get_next_line.h"
int BUFFER_SIZE 32;

void	find_new_line(char *string, char **line)
{
	int i;

	i = 0;
	while (s != '\n')
		(*line)[i++] = *s++;
}

int		get_next_line(int fd, char **line)
{
	static	fd_buffer[1024]={0};
	char	*read_buffer;
	char	*temporary;
	int		count;

	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(read_buffer) || (fd < 0) || (!line))
		return (-1);
	
	while (count = read(fd, read_buffer, BUFFER_SIZE))
	{
		if (count == -1)
			return (-1);
		read_buffer[count] = '\0';
		if (!fd_buffer[fd])
			if (!(fd_buffer[fd] = ft_calloc(1)))
				return (-1);
		if (!(temporary = ft_strjoin(fd_buffer[fd], read_buffer)))
			return (-1);
		free(fd_buffer[fd]);
		fd_buffer[fd] = temporary;
		if (ft_strchr(fd_buffer[fd], '/n'))
			break;
	}
	find_new_line(fd_buffer[fd], line);
}
