#include "get_next_line.h"

int		find_new_line(char *string, char **line, int count)
{
	int		i;
	char	*temporary;

	i = 0;
	if (count == 0 && !string)
		return (0);
	while (string[i] != '\n')
	{
		if (string[i] == '\0')
		{
			*line = ft_strdup(string);
			//printf("%s\n", *line);
			free(string);
			return (0);
		}
		i++;
	}
	string[i++] = '\0';
	*line = ft_strdup(string);
	temporary = ft_strdup(string + i);
	free(string);
	string = temporary;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*fd_buffer;
	char		*read_buffer;
	char		*temporary;
	int			count;

	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(read_buffer) || (fd < 0) || (!line))
		return (-1);
	while (count = read(fd, read_buffer, BUFFER_SIZE))
	{
		if (count == -1)
			return (-1);
		//printf(" COUNT %d\n", count);
		read_buffer[count] = '\0';
		//printf("READ_BUFFER %s\n", read_buffer);
		if (!fd_buffer)
			if (!(fd_buffer = ft_calloc(1, 1)))
				return (-1);
		if (!(temporary = ft_strjoin(fd_buffer, read_buffer)))
			return (-1);
		//printf("TEMPORARY %s\n", temporary);
		free(fd_buffer);
		fd_buffer = temporary;
		if (ft_strchr(fd_buffer, '\n'))
			break;
	}
	printf(" COUNT %d\n", count);
	return (find_new_line(fd_buffer, line, count));
}
