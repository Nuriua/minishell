#include "../../includes/minishell.h"

int	sizeof_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**make_my_env(char **env)
{
	int		i;
	char	**my_env;

	i = 0;
	my_env = malloc(sizeof(char *) * sizeof_env(env) + 1);
	while (env[i])
	{
		my_env[i] = ft_strdup(env[i]);
		i++;
	}
	my_env[i] = NULL;
	return (my_env);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	int		len;
	char	**my_env;

	(void)argc;
	(void)argv;
	i = 0;
	my_env = make_my_env(env);
	len = sizeof_env(my_env);
	while (i < len)
	{
		write(1, my_env[i], ft_strlen(my_env[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
