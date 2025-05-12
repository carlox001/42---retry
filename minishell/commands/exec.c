/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:53:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/12 17:36:55 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:53:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/11 19:02:22 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec(t_program *shell)
{
	int		j;
	int		check;
	char	***mtx_hub;

	mtx_hub = NULL;
	j = set_exec(shell, &mtx_hub);
	check = exec_core(shell, j, shell->num_cmd, mtx_hub);
	if (check == 1)
		return (1);
	if (check == -1)
	{
		close(shell->input);
		close(shell->output);
		return (free_matrix_pointer(mtx_hub), -1);
	}
	close(shell->output);
	close(shell->input);
	while (wait(&shell->exit_code) > 0)
	{
		printf("faccio questo\n");
		shell->exit_code /= 256;
		shell->status = (unsigned char *)ft_itoa(shell->exit_code);
		shell->exit_code = ft_atoi((const char *)shell->status);
		free(shell->status);
	}
	close_here_doc(shell);
	set_exec_signals();
	free_matrix_pointer(mtx_hub);
	return (0);
}

int	set_exec(t_program *shell, char ****mtx_hub)
{
	int	j;

	shell->output = dup(STDOUT_FILENO);
	shell->input = dup(STDIN_FILENO);
	shell->num_cmd = count_commands(shell->mtx_line, shell);
	*mtx_hub = alloc_mtx(shell->num_cmd, shell);
	free_matrix(shell->mtx_line);
	j = shell->num_cmd - 1;
	shell->i = 0;
	return (j);
}

int	exec_core(t_program *shell, int j, int num_cmd, char ***mtx_hub)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (num_cmd == 1 && shell->flag_builtin >= 1)
	{
		check = exec_one_command(shell, i, mtx_hub);
		if (check == 1)
			return (1);
		if (check == -1)
			return (-1);
	}
	else
	{
		printf("check: %d\n", check);
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
	if (k == -1)
		return (-1);
	if (redir_output(shell, k, i, mtx_hub) == 1)
		return (1);
	if (k - 1 >= 0)
		dup2(shell->out[k - 1], STDOUT_FILENO);
	shell->mtx_line = matrix_dup(mtx_hub[i]);
	if (check_commands(shell->mtx_line[0], shell, -1, mtx_hub) == 1)
		return (1);
	if (k - 1 >= 0)
		close_in_out(shell->out, k - 1, 1);
	dup2(shell->output, STDOUT_FILENO);
	close(shell->output);
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
		{
			close(shell->input);
			close(shell->output);
			return (1);
		}
		id = fork();
		if (id == -1)
			return (1);
		else if (id == 0)
		{
			if (child(shell, i, j, mtx_hub) == 1)
				failed_child(shell, mtx_hub);
		}
		else
			father(shell, j);
		update_counter_exec(&j, &i);
	}
	return (0);
}
