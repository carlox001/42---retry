/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_command_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:30:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/02 17:44:05 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* char *args[2];

args[0] = "ls";
args[1] = NULL;
execve("/bin/ls", args, NULL); */

void	ft_cd(t_program *shell)
{
	
	if (shell->mtx_line[shell->i + 1] == NULL)
		only_cd(shell);
	else if (shell->mtx_line[shell->i + 2] != NULL)
	{
		printf("shell: cd: too many arguments\n");
		shell->exit_code = 1;
	}
	else if (no_char(shell->mtx_line[shell->i + 1]) == 0)
	{
		cd_no_char(shell->mtx_line[shell->i + 1], shell);
		shell->exit_code = 0;
		return ;
	}
	else if (cd_absolute_path(shell->mtx_line[shell->i + 1], shell) == 1)
		return ;
	else if (cd_relative_path(shell->mtx_line[shell->i + 1], shell) == -1)
	{
		shell->exit_code = 1;
		printf("cd: %s: No such file or directory\n", shell->mtx_line[shell->i + 1]);
	}
	shell->exit_code = 0;
	return ;
}
