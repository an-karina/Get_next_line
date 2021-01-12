
size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}


void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*(p++) = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(dst);
	i = n + ft_strlen(src);
	if (n >= dstsize)
		return (dstsize + ft_strlen(src));
	while (*dst)
		dst++;
	while (*src != '\0' && (dstsize - n - 1))
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	n = ft_strlen(src);
	if (dstsize == 0)
		return (n);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*p;

	if (!s1 && !s2)
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
	return (p);
}


char	*ft_strchr(const char *s, int c)
{
	unsigned char	sym;
	char			*p;

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
