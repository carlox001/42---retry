/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:35 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/25 17:05:55 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error_cringe(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	close_child(int flag, t_program *shell, char ****mtx_hub)
{
	char	*tmp;
	int		fd;

	tmp = remove_couple_quotes(*mtx_hub[0][0]);
	free_matrix_pointer(*mtx_hub);
	if (flag == 1)
		free_all(shell, 1);
	close(shell->input);
	close(shell->output);
	fd = open(tmp, __O_DIRECTORY);
	if (shell->num_cmd != 1 && flag == 1)
		correct_exit(shell->exit_code);
	if (fd >= 0)
	{
		ft_putstr_fd("shell: ", 2);
		ft_putstr_fd(tmp, 2);
		ft_putstr_fd(": is a directory\n", 2);
		close(fd);
		free(tmp);
		correct_exit(126);
	}
	else
		else_close_child(tmp);
}

void	else_close_child(char *tmp)
{
	ft_putstr_fd("shell: ", 2);
	ft_putstr_fd(tmp, 2);
	free(tmp);
	ft_putstr_fd(": no such file or directory\n", 2);
	correct_exit(127);
}

void	correct_exit(int code)
{
	close(1);
	close(0);
	exit(code);
}

void	if_redirect(t_program *shell, char **path)
{
	shell->tmp = remove_couple_quotes(shell->mtx_line[0]);
	*path = path_find(shell->env, shell->tmp);
	if (*path == NULL && is_builtin(shell->tmp) == 0 && \
	shell->tmp[0] != '.')
		print_error_cringe(shell->tmp);
	else if (shell->num_fd >= 0)
		dup2(shell->out[shell->num_fd], STDOUT_FILENO);
	else
		dup2(shell->fd[1], STDOUT_FILENO);
	if (*path && shell->tmp[0] == '.')
		free(*path);
	close_all_files(shell->fd, shell->output, shell->input);
	free(shell->tmp);
}
