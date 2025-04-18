/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:53:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/18 11:21:56 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec(t_program *shell)
{
	int		j;
	int		num_cmd;
	char	***mtx_hub;

	shell->output = dup(STDOUT_FILENO);
	shell->input = dup(STDIN_FILENO);
	num_cmd = count_commands(shell->mtx_line, shell);
	shell->num_cmd = num_cmd;
	mtx_hub = alloc_mtx(num_cmd, shell);
	free_matrix(shell->mtx_line);
	j = num_cmd - 1;
	shell->i = 0;
	if (exec_core(shell, j, num_cmd, mtx_hub) == 1)
		return (1);
	close(shell->output);
	close(shell->input);
	//waitpid
	while (wait(NULL) > 0)
		;
	signal(SIGINT, sig_handler);
	free_matrix_pointer(mtx_hub);
	return (0);
}

int	exec_core(t_program *shell, int j, int num_cmd, char ***mtx_hub)
{
	int		i;
	int		id;
	int		k;

	i = 0;
	if (num_cmd == 1 && shell->flag_builtin == 1)
	{
		// k = open_files_in(mtx_hub[i], shell);
		// printf("entro: %d\n", k);
		// if (k - 1 >= 0)
		// 	close_in_out(shell->in, k - 1, 1);
		shell->num_fd = open_files_in(mtx_hub[i], shell);
		if (redir_input(shell, i, mtx_hub, 1) == 1)
		{
			printf("sarmi\n");
			return (-1);
		}

			
		k = open_files_out(mtx_hub[i], shell);
		if (redir_output(shell, k, i, mtx_hub) == 1)
			return (1);
		if (k - 1 >= 0)
			dup2(shell->out[k - 1], STDOUT_FILENO);
		shell->mtx_line = matrix_dup(mtx_hub[i]);
		printf("mtx_line: %s\n", shell->mtx_line[0]);
		check_commands(shell->mtx_line[0], shell, -1, 0);
		if (k - 1 >= 0)
			close_in_out(shell->out, k - 1, 1);
		// free_matrix(shell->mtx_line);
		dup2(shell->output, STDOUT_FILENO);

	}
	else
	{
		signal(SIGINT, sig_handler_child);
		while (i < num_cmd)
		{
			if (pipe(shell->fd) == -1)
				return (-1);
			id = fork();
			shell->fork_id = id;
			if (id == -1)
				return (-1);
			else if (id == 0)
				child(shell, i, j, mtx_hub);
			else
				father(shell, j);
			j--;
			i++;
		}
	}
	return (0);
}

void	child(t_program *shell, int i, int pipe_cmd, char ***mtx_hub)
{
	char	*path;

	// signal(SIGINT, sig_handler_child);
	shell->num_fd = open_files_in(mtx_hub[i], shell);
	if (redir_input(shell, i, mtx_hub, 0) == 1)
	{
		printf("sarmi\n");
		return ;
	}
	// signal(SIGINT, sig_handler_child);
	shell->num_fd = open_files_out(mtx_hub[i], shell);
	if (redir_output(shell, shell->num_fd, i, mtx_hub) == 1)
		return ;
	shell->num_fd--;
	shell->mtx_line = matrix_dup(mtx_hub[i]);
	if (pipe_cmd > 0)
	{
		if (shell->num_fd >= 0)
			dup2(shell->out[shell->num_fd], STDOUT_FILENO);
		else
			dup2(shell->fd[1], STDOUT_FILENO);
		close_all_files(shell->fd, shell->output, shell->input);
	}
	else if (pipe_cmd == 0)
	{
		path = path_find(shell->env, shell->mtx_line[0]);
		if (path == NULL && shell->flag_builtin == 0)
			printf("%s: command not found\n", shell->mtx_line[0]);
		else if (shell->num_fd >= 0)
			dup2(shell->out[shell->num_fd], STDOUT_FILENO);
		else
			dup2(shell->output, STDOUT_FILENO);
		close_all_files(shell->fd, shell->output, shell->input);
	}
	if (check_commands(shell->mtx_line[0], shell, shell->num_fd, mtx_hub) == 1)
	{
		free_matrix_pointer(mtx_hub);
		if (shell->num_cmd != 1)
			free_all(shell, 1);
		exit(1);
	}
}

void	father(t_program *shell, int j)
{
	if (j > 0)
		close_fds(shell->fd, 1, shell->input);
	else if (j == 0)
		close_fds(shell->fd, 0, shell->input);
	
}


char	***alloc_mtx(int num_commands, t_program *shell)
{
	char	***mtx_hub;
	char	**dup_mtx;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	mtx_hub = (char ***)ft_calloc(sizeof(char **), (num_commands + 1));
	if (mtx_hub == NULL)
		return (NULL);
	while (shell->mtx_line[i])
	{
		if (k == 0)
		{
			dup_mtx = (char **)ft_calloc(sizeof(char *), (matrix_len(shell->mtx_line) + 1));
			if (dup_mtx == NULL)
				return (NULL);
		}
		if (shell->mtx_line[i][0] == '|')
		{
			mtx_hub[j] = matrix_dup(dup_mtx);
			j++;
			i++;
			free_matrix(dup_mtx);
			k = 0;
		}
		else
		{
			dup_mtx[k] = ft_strdup(shell->mtx_line[i]);
			k++; 
			i++;
		}
	}
	if (dup_mtx[0] != NULL || dup_mtx[0][0] != '\0')
	{
		mtx_hub[j] = matrix_dup(dup_mtx);
		j++;
	}
	free_matrix(dup_mtx);
	mtx_hub[j] = NULL;
	return (mtx_hub);
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
			i+=2;
		if (mtx[i] != NULL && mtx[i][0] == '|')
			count++;
		if (mtx[i] != NULL && ((ft_strncmp(mtx[i], "echo", 2) == 0 && ft_strlen(mtx[i]) == 4) || \
			(ft_strncmp(mtx[i], "pwd", 2) == 0 && ft_strlen(mtx[i]) == 3) || \
			(ft_strncmp(mtx[i], "env", 2) == 0 && ft_strlen(mtx[i]) == 3) || \
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

void	free_matrix_pointer(char ***mtx_hub)
{
	int	i;

	i = 0;
	while (mtx_hub[i])
	{
		free_matrix(mtx_hub[i]);
		i++;
	}
	free(mtx_hub);
}
