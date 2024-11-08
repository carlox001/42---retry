#include <unistd.h>

int	main(int ac, char **av)
{
	int	n;

	n = 0;
	if (ac > 1)
	{
		while (av[ac - 1][n] != '\0')
		{
			write(1, &av[ac - 1][n], 1);
			n++;
		}
	}
	write(1, "\n", 1);
	return(0);
}