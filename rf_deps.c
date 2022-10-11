#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize)
{
	size_t	i;

	if (cpysize)
	{
		i = 0;
		while (src[i] != '\0' && i < cpysize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	res;
	size_t	i;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	i = 0;
	if (size > dlen)
	{
		res = dlen + slen;
		while (src[i] != '\0' && (dlen + 1) < size)
		{
			dst[dlen] = src[i];
			dlen++;
			i++;
		}
		dst[dlen] = '\0';
	}
	else
		res = size + slen;
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	joined_size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	joined_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(sizeof(char) * joined_size);
	if (joined == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(joined, s1, ft_strlen(s1) + 1);
	ft_strlcat(joined, s2, joined_size);
	free(s1);
	return (joined);
}

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
		c++ ;
	return (c);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		count;
	int		size;

	count = 0;
	size = 0;
	while (s1[size])
		++size;
	str = malloc(sizeof(char) * (size + 1));
	while (s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

char	*ft_is_lesser(char *substr)
{
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	return (substr);
}
