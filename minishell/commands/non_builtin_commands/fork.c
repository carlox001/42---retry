/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:35 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/16 17:49:52 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// il figlio che esegue i comandi dell'execve
int	child(t_program *shell, int i, int pipe_cmd, char ***mtx_hub)
{
	char	*path;
	int		flag;

	shell->flag_cmd_not_found = 0;
	flag = 0;
	if (open_files_in_child(shell, i, mtx_hub) == -1)
		return (1);
	shell->mtx_line = matrix_dup(mtx_hub[i]);
	path = NULL;
	redirect_in_out_child(shell, pipe_cmd, path);
	if (is_builtin(shell->mtx_line[0]) == 1)
		flag = 1;
	if (check_commands(shell->mtx_line[0], shell, shell->num_fd, mtx_hub) == 1)
	{
		free_matrix_pointer(mtx_hub);
		if (flag == 1)
			free_all(shell, 1);
		close(shell->input);
		if (shell->num_cmd != 1 && flag == 1)
			exit(shell->exit_code);
		exit(127);
	}
	return (0);
}

// apre i file in input e output e imposta 
//come flussi gli ultimi file aperti
int	open_files_in_child(t_program *shell, int i, char ***mtx_hub)
{
	shell->num_fd = open_files_in(mtx_hub[i], shell);
	if (shell->num_fd == -1)
		return (-1);
	if (redir_input(shell, i, mtx_hub, 0) == 1)
	{
		free_all(shell, 1);
		free_matrix_pointer(mtx_hub);
		exit(1);
	}
	shell->num_fd = open_files_out(mtx_hub[i], shell);
	if (shell->num_fd == -1)
		return (-1);
	if (redir_output(shell, shell->num_fd, i, mtx_hub) == 1)
	{
		free_all(shell, 1);
		free_matrix_pointer(mtx_hub);
		exit(1);
	}
	shell->num_fd--;
	return (0);
}

// redirige l'input e l'output dei comandi del programma
void	redirect_in_out_child(t_program *shell, int pipe_cmd, char *path)
{
	if (pipe_cmd > 0)
	{
		if (shell->num_fd >= 0)
			dup2(shell->out[shell->num_fd], STDOUT_FILENO);
		else
			dup2(shell->fd[1], STDOUT_FILENO);
		close_all_files(shell->fd, shell->output, shell->input);
	}
	else
	{
		shell->tmp = shell->mtx_line[0];
		shell->mtx_line[0] = remove_couple_quotes(shell->mtx_line[0]);
		free(shell->tmp);
		path = path_find(shell->env, shell->mtx_line[0], shell);
		if (path == NULL && is_builtin(shell->mtx_line[0]) == 0 && \
		shell->mtx_line[0][0] != '.')
			print_error_cringe(shell->mtx_line[0]);
		else if (shell->num_fd >= 0)
			dup2(shell->out[shell->num_fd], STDOUT_FILENO);
		else
			dup2(shell->output, STDOUT_FILENO);
		if (path && shell->mtx_line[0][0] == '.')
			free(path);
		close_all_files(shell->fd, shell->output, shell->input);
	}
}

void	father(t_program *shell, int j)
{
	if (j > 0)
		close_fds(shell->fd, 1, shell->input);
	else if (j == 0)
		close_fds(shell->fd, 0, shell->input);
}

void	failed_child(t_program *shell, char ***mtx_hub)
{
	close(shell->fd[0]);
	close(shell->fd[1]);
	close(shell->input);
	close(shell->output);
	free_matrix_pointer(mtx_hub);
	free_all(shell, 1);
	exit(1);
}
