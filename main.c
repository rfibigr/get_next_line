#include "get_next_line.h"

int main (int ac, char **av)
{
	int fd;
	char *line;
	line = NULL;

	if(ac == 2)
	{
	fd = open(av[1], O_RDONLY);
	
	while (get_next_line(fd, &line) > 0)
	{
			ft_putstr(line);
			ft_putstr("NEXT");
	}
	}
	return (0);
	
}
