#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		gnl_res;

	if (argc == 1)
	{
		ft_putstr("=!= NO FILE PASSED =!=");
		return (-1);
	}

	ft_putstr("\n----------- MAIN -----------\n= OPENNING FILE [");
	ft_putstr(argv[1]);
	ft_putstr("] =\n");
	fd = open(argv[1], O_RDONLY);

	ft_putstr("\n---------- RESULT ----------");

	ft_putstr("\n\n----------  LINE  ----------");
	gnl_res = get_next_line(fd, &line);
	ft_putstr("\n GNL : ");
	ft_putnbr(gnl_res);
	ft_putstr("\nLINE : [");
	ft_putstr(line);
	ft_putstr("]\n");
	ft_putstr("\n----------------------------");

	ft_putstr("\n\n----------  LINE  ----------");
	gnl_res = get_next_line(fd, &line);
	ft_putstr("\n GNL : ");
	ft_putnbr(gnl_res);
	ft_putstr("\nLINE : [");
	ft_putstr(line);
	ft_putstr("]\n");
	ft_putstr("\n----------------------------");

	ft_putstr("\n\n----------  LINE  ----------");
	gnl_res = get_next_line(fd, &line);
	ft_putstr("\n GNL : ");
	ft_putnbr(gnl_res);
	ft_putstr("\nLINE : [");
	ft_putstr(line);
	ft_putstr("]\n");
	ft_putstr("\n----------------------------");

	ft_putstr("\n\n----------  LINE  ----------");
	gnl_res = get_next_line(fd, &line);
	ft_putstr("\n GNL : ");
	ft_putnbr(gnl_res);
	ft_putstr("\nLINE : [");
	ft_putstr(line);
	ft_putstr("]\n");
	ft_putstr("\n----------------------------");
/*
	ft_putstr("\n\n----------  LINE  ----------");
	gnl_res = get_next_line(fd, &line);
	ft_putstr("\n GNL : ");
	ft_putnbr(gnl_res);
	ft_putstr("\nLINE : [");
	ft_putstr(line);
	ft_putstr("]\n");
	ft_putstr("\n----------------------------");
*/
	ft_putstr("\n----------- TEST -----------\n-1 : ERROR\n 0 : EOF\n 1 : LINE\n");
}