#include "get_next_line.h"

int main (int ac, char **av)
{
	int fd;
	char *line;
	int i = 0;
	
	if(ac == 2)
	{
	fd = open(av[1], O_RDONLY);
	line = 0;
	
	while ((get_next_line(fd, &line) > 0) && i++ < 10)
	{
			ft_putstr("<|>");
			ft_putstr(line);
	}
	}
	return (0);
	
}
