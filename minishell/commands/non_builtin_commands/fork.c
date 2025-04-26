/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:35 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/25 14:51:03 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// il figlio che esegue i comandi dell'execve
int	child(t_program *shell, int i, int pipe_cmd, char ***mtx_hub)
{
	char	*path;

	if (open_files_in_child(shell, i, mtx_hub) == -1)
		return (1);
	shell->mtx_line = matrix_dup(mtx_hub[i]);
    path = NULL;
    redirect_in_out_child(shell, pipe_cmd, path);
	if (check_commands(shell->mtx_line[0], shell, shell->num_fd, mtx_hub) == 1)
	{
		free_matrix_pointer(mtx_hub);
		if (shell->num_cmd != 1 && shell->flag_builtin > 0)
			free_all(shell, 1);
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
void    redirect_in_out_child(t_program *shell, int pipe_cmd, char *path)
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
		shell->mtx_line[0] = remove_all_quotes(shell->mtx_line[0]);
		free(shell->tmp);
		path = path_find(shell->env, shell->mtx_line[0]);
		if (path == NULL && shell->flag_builtin == 0)
		{
			printf("%s: command not found\n", shell->mtx_line[0]);
		}
		else if (shell->num_fd >= 0)
			dup2(shell->out[shell->num_fd], STDOUT_FILENO);
		else
			dup2(shell->output, STDOUT_FILENO);
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
