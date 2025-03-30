/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_hub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:04 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/29 18:33:10 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_commands(char *cmd, t_program *shell) 
{
	if (check_builtin(cmd, shell) == 1)
		return (1);
	// if (check_non_builtin(cmd, shell) == 1)
	return (0);
}

int	check_builtin(char *cmd, t_program *shell)
{
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		ft_echo(shell);
	// if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
	// 	cd();
	else if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		ft_pwd();
	else if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		ft_export(shell);
	else if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0)
		ft_unset(shell);
	else if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		ft_env(shell);
	else if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		ft_exit(shell);
	return (0);
}

