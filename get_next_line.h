#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}		t_bool;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*get_line(char *str);
char	*get_buffer(int fd, char *str);
char	*prepare_next_line(char *str);

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
t_bool	ft_strchr(char *s, char c);
char	*ft_strdup(const char *src);

#endif