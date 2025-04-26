/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:53:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/25 14:57:54 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec(t_program *shell)
{
	int		j;
	int		check;
	char	***mtx_hub;

	shell->output = dup(STDOUT_FILENO);
	shell->input = dup(STDIN_FILENO);
	shell->num_cmd = count_commands(shell->mtx_line, shell);
	mtx_hub = alloc_mtx(shell->num_cmd, shell);
	free_matrix(shell->mtx_line);
	j = shell->num_cmd - 1;
	shell->i = 0;
	check = exec_core(shell, j, shell->num_cmd, mtx_hub);
	if (check == 1)
		return (1);
	if (check == -1)
		return (1);
	close(shell->output);
	close(shell->input);
	while (wait(&shell->exit_code) > 0)
	{
		if (shell->exit_code >= 256)
			shell->exit_code /= 256;
	}
	close_here_doc(shell);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	free_matrix_pointer(mtx_hub);
	return (0);
}

int	exec_core(t_program *shell, int j, int num_cmd, char ***mtx_hub)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (num_cmd == 1 && shell->flag_builtin == 1)
	{
		check = exec_one_command(shell, i, mtx_hub);
		if (check == 1)
			return (1);
		if (check == -1)
			return (-1);
	}
	else
	{
		check = exec_more_commands(shell, j, i, mtx_hub);
		if (check == 1)
			return (1);
		if (check == -1)
			return (-1);
	}
	return (0);
}

int	exec_one_command(t_program *shell, int i, char ***mtx_hub)
{
	int		k;

	shell->num_fd = open_files_in(mtx_hub[i], shell);
	if (shell->num_fd == -1)
		return (-1);
	if (redir_input(shell, i, mtx_hub, 1) == 1)
		return (1);
	k = open_files_out(mtx_hub[i], shell);
	if (redir_output(shell, k, i, mtx_hub) == 1)
		return (1);
	if (k - 1 >= 0)
		dup2(shell->out[k - 1], STDOUT_FILENO);
	shell->mtx_line = matrix_dup(mtx_hub[i]);
	check_commands(shell->mtx_line[0], shell, -1, 0);
	if (k - 1 >= 0)
		close_in_out(shell->out, k - 1, 1);
	dup2(shell->output, STDOUT_FILENO);
	return (0);
}

int	exec_more_commands(t_program *shell, int j, int i, char ***mtx_hub)
{
	int		id;

	signal(SIGINT, sig_handler_child);
	signal(SIGQUIT, sig_handler_child);
	while (i < shell->num_cmd)
	{
		if (pipe(shell->fd) == -1)
			return (1);
		id = fork();
		shell->fork_id = id;
		if (id == -1)
			return (1);
		else if (id == 0)
		{
			if (child(shell, i, j, mtx_hub) == 1)
			{
				close(shell->fd[0]);
				close(shell->fd[1]);
				free_matrix_pointer(mtx_hub);
				free_all(shell, 1);
				exit(1);
			}
			
		}
		else
			father(shell, j);
		j--;
		i++;
	}
	return (0);
}

int	count_commands(char **mtx, t_program *shell)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	shell->flag_builtin = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == '<' || mtx[i][0] == '>')
			i += 2;
		if (mtx[i] != NULL && mtx[i][0] == '|')
			count++;
		if (mtx[i] != NULL && \
			((ft_strncmp(mtx[i], "echo", 4) == 0 && ft_strlen(mtx[i]) == 4) || \
			(ft_strncmp(mtx[i], "pwd", 3) == 0 && ft_strlen(mtx[i]) == 3) || \
			(ft_strncmp(mtx[i], "env", 3) == 0 && ft_strlen(mtx[i]) == 3) || \
			(ft_strncmp(mtx[i], "cd", 2) == 0 && ft_strlen(mtx[i]) == 2) || \
			(ft_strncmp(mtx[i], "export", 6) == 0 && ft_strlen(mtx[i]) == 6) || \
			(ft_strncmp(mtx[i], "unset", 5) == 0 && ft_strlen(mtx[i]) == 5) || \
			(ft_strncmp(mtx[i], "exit", 4) == 0 && ft_strlen(mtx[i]) == 4)))
			shell->flag_builtin++;
		if (mtx[i] != NULL)
			i++;
	}
	return (count);
}
