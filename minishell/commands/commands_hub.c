/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_hub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:04 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/12 17:51:30 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_commands(char *cmd, t_program *shell, int k, char ***mtx_hub)
{
	int	check;

	if (k != -1)
		close_in_out(shell->out, k, 1);
	check = check_builtin(cmd, shell, mtx_hub);
	if (check == 1)
	{
		shell->flag_builtin = 1;
		free_matrix(shell->mtx_line);
		return (1);
	}
	else if (exec_non_builtin(shell, 0, mtx_hub) == 1)
		return (1);
	return (0);
}

int	check_builtin(char *cmd, t_program *shell, char ***mtx_hub)
{
	if (ft_strncmp(cmd, "echo", 4) == 0 && ft_strlen(cmd) == 4)
		return (ft_echo(shell), 1);
	else if (ft_strncmp(cmd, "pwd", 3) == 0 && ft_strlen(cmd) == 3)
		return (ft_pwd(), 1);
	else if (ft_strncmp(cmd, "env", 3) == 0 && ft_strlen(cmd) == 3)
		return (ft_env(shell), 1);
	else if (ft_strncmp(cmd, "cd", 2) == 0 && ft_strlen(cmd) == 2)
		return (ft_cd(shell), 1);
	else if (ft_strncmp(cmd, "export", 6) == 0 && ft_strlen(cmd) == 6)
		return (ft_export(shell), 1);
	else if (ft_strncmp(cmd, "unset", 5) == 0 && ft_strlen(cmd) == 5)
		return (ft_unset(shell), 1);
	else if (ft_strncmp(cmd, "exit", 4) == 0 && ft_strlen(cmd) == 4)
		return (ft_exit(shell, mtx_hub), 1);
	return (0);
}

int	exec_non_builtin(t_program *shell, int index, char ***mtx_hub)
{
	char	**full_cmd;

	shell->path = path_find(shell->env, shell->mtx_line[index], shell);
	if (shell->path == NULL)
	{
		shell->i = matrix_len(shell->mtx_line);
		return (free(shell->path), free_all(shell, 0), 1);
	}
	full_cmd = get_full_cmd(shell);
	if (execve(shell->path, full_cmd, shell->env) == -1)
	{
		shell->flag_cmd_not_found = 1;
		ft_putstr_fd("shell: ", 2);
		ft_putstr_fd(shell->mtx_line[0], 2);
		ft_putstr_fd(": no such file or directory\n", 2);
		failed_execve(full_cmd, shell, mtx_hub);
		exit(127);
	}
	return (0);
}

void	failed_execve(char **full_cmd, t_program *shell, char ***mtx_hub)
{
	int	fd;

	fd = open(full_cmd[0], __O_DIRECTORY);
	if (fd > 0)
	{
		printf("shell: %s: is a directory\n", full_cmd[0]);
		clear_non_builtin(shell, mtx_hub, &shell->path, &full_cmd);
		close(fd);
		exit(126);
	}
	else
		clear_non_builtin(shell, mtx_hub, &shell->path, &full_cmd);
}

void	clear_non_builtin(t_program *shell, char ***mtx_hub, \
char **path, char ***full_cmd)
{
	free(*path);
	free_matrix(*full_cmd);
	free_all(shell, 1);
	free_matrix_pointer(mtx_hub);
	free(shell->mtx_line);
}
