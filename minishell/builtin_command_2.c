/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_command_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:30:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/17 14:28:19 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// extern int	signals = 0;


void	ft_cd(t_program *shell)
{
	
	if (shell->mtx_line[shell->i + 1] == NULL)
		only_cd(shell);
	else if (shell->mtx_line[shell->i + 2] != NULL)
	{
		printf("shell: cd: too many arguments\n");
		shell->i = matrix_len(shell->mtx_line);
		shell->exit_code = 1;
	}
	else if (no_char(shell->mtx_line[shell->i + 1]) == 0)
	{
		cd_no_char(shell->mtx_line[shell->i + 1], shell);
		shell->i = matrix_len(shell->mtx_line);
		shell->exit_code = 0;
		return ;
	}
	else if (cd_absolute_path(shell->mtx_line[shell->i + 1], shell) == 1)
		return ;
	else if (cd_relative_path(shell->mtx_line[shell->i + 1], shell) == -1)
	{
		shell->exit_code = 1;
		printf("cd: %s: No such file or directory\n", shell->mtx_line[shell->i + 1]);
		shell->i = matrix_len(shell->mtx_line);
	}
	shell->exit_code = 0;
	shell->i = matrix_len(shell->mtx_line);
	return ;
}
