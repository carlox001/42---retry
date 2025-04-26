/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:33:45 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/26 17:09:27 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redir_input(t_program *shell, int i, char ***mtx_hub, int flag)
{
	char	**tmp;

	if (shell->num_fd == -1)
		return (1);
	if (shell->num_fd > 0)
	{
		tmp = realloc_without_redir(mtx_hub[i], shell->num_fd, '<');
		if (tmp[0] == NULL)
		{
			close_in_out(shell->in, shell->num_fd - 1, 1);
			close_in_out(shell->fd, 2, 0);
			free_matrix(tmp);
			free_all(shell, 1);
			return (free_matrix_pointer(mtx_hub), exit(1), 1);
		}
		free_matrix(mtx_hub[i]);
		mtx_hub[i] = matrix_dup(tmp);
		free_matrix(tmp);
		if (flag != 1)
			dup2(shell->in[shell->num_fd - 1], STDIN_FILENO);
		close_in_out(shell->in, shell->num_fd - 1, 1);
	}
	if (mtx_hub[i][0] == NULL)
		return (1);
	return (0);
}

int	open_files_in(char **mtx, t_program *shell)
{
	int	i;
	int	j;

	i = counter_in_out('<', mtx);
	if (i == 0)
		return (0);
	shell->in = (int *)malloc(sizeof(int) * i);
	if (shell->in == NULL)
		return (-1);
	initialize_files_in(&i, &j, &shell->num_hd, 1);
	while (mtx[i])
	{
		if (mtx[i][0] == '<' && mtx[i][1] == '<')
		{
			if (open_file_in_hd(&i, &j, &shell->num_hd, shell->in) == -1)
				return (-1);
		}
		else if (mtx[i][0] == '<' && mtx[i][1] == '>')
		{
			shell->flag_in_operator = 1;
			if (open_file_in_fd(&i, &j, mtx, shell) == -1)
				return (-1);
		}
		else if (mtx[i][0] == '<')
		{
			if (open_file_in_fd(&i, &j, mtx, shell) == -1)
			{
				close(shell->input);
				close(shell->output);
				free(shell->in);
				return (-1);
			}
		}
		i++;
	}
	return (j);
}

void	initialize_files_in(int *i, int *j, int *num_hd, int flag)
{
	(*i) = 0;
	(*j) = 0;
	if (flag == 1)
		(*num_hd) = 0;
}

int	open_file_in_hd(int *i, int *j, int *num_hd, int *shell_in)
{
	char	*file;
	char	*tmp;

	tmp = ft_itoa(*num_hd);
	file = ft_strjoin(".here_doc_", tmp);
	shell_in[*j] = open(file, O_RDONLY, 0777);
	free(tmp);
	free(file);
	if (shell_in[*j] == -1)
	{
		free(shell_in);
		return (-1);
	}
	(*i)++;
	(*j)++;
	(*num_hd)++;
	return (0);
}

int	open_file_in_fd(int *i, int *j, char **mtx, t_program *shell)
{
	(*i)++;
	if (shell->flag_in_operator == 1)
	{
		if (access(mtx[*i], F_OK) == -1)
			shell->in[*j] = open((mtx[*i]), O_CREAT);
		else
			shell->in[*j] = open((mtx[*i]), O_RDONLY);
	}
	else
		shell->in[*j] = open((mtx[*i]), O_RDONLY);
	shell->flag_in_operator = 0;
	if (shell->in[*j] == -1)
	{
		printf("shell %s: No such file or directory\n", (mtx[*i]));
		return (-1);
	}
	(*j)++;
	return (0);
}
