#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main (void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}