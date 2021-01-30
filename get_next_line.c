/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:40:52 by jhleena           #+#    #+#             */
/*   Updated: 2021/01/20 13:30:13 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_new_line(char **string, char **line, int count)
{
	int		i;
	char	*temporary;

	i = 0;
	if (count == 0 && !*string)
		return (0);
	while ((*string)[i] != '\n' && (*string)[i] != '\0')
		i++;
	if ((*string)[i] == '\0')
	{
		free(*line);
		if (!(*line = ft_strdup(*string)))
			return (-1);
		free(*string);
		*string = NULL;
		return (0);
	}
	(*string)[i++] = '\0';
	free(*line);
	if (!(*line = ft_strdup(*string)))
		return (-1);
	temporary = ft_strdup(*string + i);
	free(*string);
	*string = temporary;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*fd_buffer;
	char		*read_buffer;
	int			count;

	if ((fd < 0) || (!line) || (BUFFER_SIZE < 1) ||
		(read(fd, 0, 0) < 0) || !(read_buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	*line = ft_calloc(1, 1);
	while ((count = read(fd, read_buffer, BUFFER_SIZE)))
	{
		if (count == -1)
		{
			free(read_buffer);
			return (-1);
		}
		read_buffer[count] = '\0';
		fd_buffer = (!fd_buffer) ? ft_calloc(1, 1) : fd_buffer;
		if (!(fd_buffer = ft_strjoin_free(fd_buffer, read_buffer)))
			return (-1);
		if ((ft_strchr(fd_buffer, '\n')))
			break ;
	}
	free(read_buffer);
	return (find_new_line(&fd_buffer, line, count));
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*p;

	if (!s1 || !s2)
		return (NULL);
	p = NULL;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (p)
	{
		ft_strlcpy(p, s1, len_s1 + 1);
		if (len_s2)
			ft_strlcat(p, s2, len_s2 + len_s1 + 1);
	}
	free(s1);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	sym;
	char			*p;

	if (!s)
		return (NULL);
	sym = (unsigned char)c;
	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == sym)
			return (p);
		p++;
	}
	if (sym == '\0')
		return (p);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	p = malloc(sizeof(char) * (len + 1));
	if (p)
	{
		while (len--)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
