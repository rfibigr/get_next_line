#include "get_next_line.h"

int main (int ac, char **av)
{
	int fd;
	char *line;
	int ret;
//	int i = 0;
	ret = 0;
	
	if(ac == 2)
	{
	fd = open(av[1], O_RDONLY);
	line = 0;
	
	while ((ret = (get_next_line(fd, &line)) > 0))
	{
		ft_putnbr(ret);
		ft_putchar(']');
		ft_putstr(line);
		ft_putchar('\n');
	}
	}
	return (0);
	
}
