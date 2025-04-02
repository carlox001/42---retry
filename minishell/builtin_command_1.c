/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_command_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:30:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/02 12:46:08 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_program *shell)
{
	printf("%s\n", shell->pwd);
	return (0);
}

int	ft_env(t_program *shell)
{
	shell->i = 0;

	while (shell->env[shell->i])
	{
		printf("%s\n", shell->env[shell->i]);
		shell->i++;
	}
	return (0);
}

void	ft_exit(t_program *shell)
{
	printf("exit\n");
	free_all(shell);
	exit(0);
}
