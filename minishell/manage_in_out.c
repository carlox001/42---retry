/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_in_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:54:56 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/17 19:02:39 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	counter_in_out(char c, char **mtx)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == c)
			counter++;
		i++;
	}
	return (counter);
}

int	open_files_in(char **mtx, t_program *shell)
{
	int		i;
	int		j;
	char	*file;
	char	*tmp;

	i = counter_in_out('<', mtx);
	if (i == 0)
		return (0);
	shell->in = (int *)malloc(sizeof(int) * i);
	if (shell->in == NULL)
		return (-1);	
	i = 0;
	j = 0;
	shell->num_hd = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == '<' && mtx[i][1] == '<')
		{
			tmp = ft_itoa(shell->num_hd);
			file = ft_strjoin(".here_doc_", tmp);
			shell->in[j] = open(file, O_RDONLY, 0777);
			free(tmp);
			free(file);
			if (shell->in[j] == -1)
			{
				free(shell->in);
				return (-1);
			}
			i++;
			j++;
			shell->num_hd++;
		}
		else if (mtx[i][0] == '<')
		{
			i++;
			shell->in[j] = open(mtx[i], O_RDONLY);
			if (shell->in[j] == -1)
			{
				printf("shell: %s: No such file or directory\n", mtx[i]);
				free(shell->in);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (j);
}

int	open_files_out(char **mtx, t_program *shell)
{
	int	i;
	int	j;

	i = counter_in_out('>', mtx);
	if (i == 0)
		return (0);
	shell->out = (int *)malloc(sizeof(int) * i);
	if (shell->out == NULL)
		return (-1);	
	i = 0;
	j = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == '>' && mtx[i][1] == '>')
		{
			i++;
			shell->out[j] = open(mtx[i], O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (shell->out[j] == -1)
			{
				printf("shell: %s: error\n", mtx[i]);
				free(shell->out);
				return (-1);
			}
			j++;
		}
		else if (mtx[i][0] == '>')
		{
			i++;
			shell->out[j] = open(mtx[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (shell->out[j] == -1)
			{
				printf("shell: %s: error\n", mtx[i]);
				free(shell->out);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (j);
}

int	redir_input(t_program *shell, int i, char ***mtx_hub, int flag)
{
	char	**tmp;

	if (shell->num_fd == -1)
		return (1);
	if (shell->num_fd > 0)
	{
		tmp = realloc_without_redir(mtx_hub[i], shell->num_fd, '<');
		print_matrix(tmp);
		if (tmp[0] == NULL)
		{
			close_in_out(shell->in, shell->num_fd - 1, 1);
			close_in_out(shell->fd, 2, 0);
			free_matrix(tmp);
			free_all(shell, 1);
			free_matrix_pointer(mtx_hub);
			exit(1);
			return (1);
		}
		free_matrix(mtx_hub[i]);
		mtx_hub[i] = matrix_dup(tmp);
		free_matrix(tmp);
		// printf("fd che duppiamo come in: %d\n", shell->in[shell->num_fd - 1]);
		if (flag != 1)
			dup2(shell->in[shell->num_fd - 1], STDIN_FILENO);
		// dup2(shell->fd[1], STDOUT_FILENO);
		close_in_out(shell->in, shell->num_fd - 1, 1);
	}
	if (mtx_hub[i][0] == NULL)
		return (1);
	return (0);
}

int	redir_output(t_program *shell, int k, int i, char ***mtx_hub)
{
	char	**tmp;

	if (k == -1)
		return (1);
	// printf("k in out: %d\n", k);
	if (k > 0)
	{
		tmp = realloc_without_redir(mtx_hub[i], k, '>');
		if (tmp[0] == NULL)
		{
			close_in_out(shell->out, k - 1, 1);
			close_in_out(shell->fd, 2, 0);
			free_matrix(tmp);
			return (1);
		}
		free_matrix(mtx_hub[i]);
		mtx_hub[i] = matrix_dup(tmp);
		free_matrix(tmp);
		// close_in_out(shell->in, k - 1, 1);
	}
	if (mtx_hub[i][0] == NULL)
		return (1);
	return (0);
}

char	**realloc_without_redir(char **mtx, int k, char c)
{
	int		i;
	int		j;
	char	**new_mtx;

	new_mtx = (char **)malloc(sizeof(char *) * (matrix_len(mtx) - (k * 2) + 1));
	if (new_mtx == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == c)
			i += 2;
		else if (mtx[i] != NULL)
		{
			new_mtx[j] = ft_strdup(mtx[i]);
			i++;
			j++;
		}
	}
	new_mtx[j] = NULL;
	return (new_mtx);
}
