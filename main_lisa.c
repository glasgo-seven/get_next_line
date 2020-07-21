#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int   main(int ac, char **av)
{
	char    *line;
	int        fd;
	int        k;

	k = 0;
	if (ac == 1)
	{
		printf("No files detected\n");
	}
	else
	{
		ac--;
		while (ac > 0)
		{
//			i = 0;
			printf("// file - %s - start //\n", av[ac]);
			fd = open(av[ac], O_RDONLY);
			int i = 0;
			while((i = get_next_line(fd, &line)) > 0)
			{
				printf("%s -- %i\n", line, i);
				if (line)
					free(line);
			}
			//get_next_line(fd, &line);
			printf("%s -- %i\n", line, i);
			if (line != NULL)
				free(line);
			//get_next_line(fd, &line);
			//printf("%s\n", line);
			//get_next_line(fd, &line);
			//printf("%s\n", line);
			//get_next_line(fd, &line);
			//printf("%s\n", line);
			printf("// file - %s - end //\n", av[ac]);
			scanf("%i",&k);
			ac--;
		}
	}
	return (0);
}
