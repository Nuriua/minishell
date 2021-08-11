#include "../../includes/minishell.h"

void	ft_putargv(int flag, char **argv, int i, int argc)
{
	int	j;

	while (argv[i])
	{
		j = 0;
		write(1, argv[i], ft_strlen(argv[i]));
		if (i != argc - 1)
			write(1, " ", 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
}

int	echo(int argc, char **argv)
{
	int		i;
	int		flag;

	i = 2;
	flag = 0;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ft_strnstr(argv[2], "-n", 2))
	{
		i++;
		flag = 1;
		if (argc == 3)
			return (0);
	}
	ft_putargv(flag, argv, i, argc);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	(void)env;
	echo(argc, argv);
	return (0);
}
