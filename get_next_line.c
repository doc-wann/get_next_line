#include "get_next_line.h"

t_bool	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (FALSE);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char *reader(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	r;

	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	r = 1;
	while (!ft_strchr(buffer, '\n'))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r == 0 || r == -1)
			break ;
		tmp[r] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (buffer == NULL)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	if (r == -1)
		return (NULL);
	return (buffer);
}

char	*cut(char *buffer)
{
	char	*line;
	size_t	in;

	in = 0;
	if(buffer[in] == '\0')
		return (NULL);
	while (buffer[in] != '\n' && buffer[in] != '\0')
		in++;
	line = malloc(sizeof(char) * (in + (buffer[in] == '\n') + 1));
	if (line == NULL)
		return (NULL);
	in = 0;
	while (buffer[in] != '\0' && buffer[in] != '\n')
	{
		line[in] = buffer[in];
		in++;
	}
	if (buffer[in] == '\n')
		line[in++] = '\n';
	line[in] = '\0';
	return (line);
}

char	*next(char *buffer)
{
	char	*next;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	next = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (next == NULL)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i + j] != '\0')
	{
		next[j] = buffer[i + j];
		j++;
	}
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	char 		*ret;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = reader(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	ret = cut(buffer);
	buffer = next(buffer);
	return (ret);
}
