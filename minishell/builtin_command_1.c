				/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_command_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:30:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/05 17:21:08 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// extern int	signals = 0;


int	ft_pwd()
{
	char	*buffer;

	buffer = getcwd(NULL, 1000);
	if (!buffer)
		return (1);
	printf("%s\n", buffer);
	free(buffer);
	return (0);
}

int	ft_env(t_program *shell)
{
	int	i;

	if (shell->mtx_line[1] != NULL)
	{
		printf("env: %s: No such file or directory\n", shell->mtx_line[1]);
		shell->exit_code = 127;
		shell->i = matrix_len(shell->mtx_line);
		return (0);
	}
	i = 0;
	while (shell->env[i])
	{
		if (is_there_an_equal(shell->env[i]) == 1)
			printf("%s\n", shell->env[i]);
		i++;
	}
	return (0);
}

int	is_there_an_equal(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		return (1);
		i++;
	}
	return (0);
}

void	ft_exit(t_program *shell)
{
	printf("exit\n");
	free_all(shell, 0);
	exit(0);
}
