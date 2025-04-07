/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:53:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/07 19:43:02 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	printf("num_commands: %d\n", num_commands);
	mtx_hub = (char ***)ft_calloc(sizeof(char **), (num_commands + 1));
	if (mtx_hub == NULL)
		return (NULL);
	while (shell->mtx_line[i])
	{
		printf("shell: %s\n", shell->mtx_line[i]);
		if (k == 0)
		{
			printf("qui\n");
			dup_mtx = (char **)ft_calloc(sizeof(char *), (matrix_len(shell->mtx_line) + 1));
			if (dup_mtx == NULL)
				return (NULL);
		}
		if (shell->mtx_line[i][0] == '|')
		{
			mtx_hub[j] = matrix_dup(dup_mtx);
			// printf("siamo nel ciclo\n");
			print_matrix(mtx_hub[j]);
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
	if (dup_mtx[0] != NULL)
	{
		mtx_hub[j] = matrix_dup(dup_mtx);
		printf("sono in menopausa\n");
		print_matrix(mtx_hub[j]);
		j++;
	}
	free_matrix(dup_mtx);
	
	mtx_hub[j] = NULL;
	return (mtx_hub);
}


int	count_commands(char **mtx_line)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (mtx_line[i])
	{
		if (mtx_line[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

int	exec(t_program *shell)
{
	int		i;
	int		id;
	int		fd[2];
	int		j;
	int		num_cmd;
	char	***mtx_hub;
	int		output;
	int		input;

	output = dup(STDOUT_FILENO);
	input = dup(STDIN_FILENO);
	num_cmd = count_commands(shell->mtx_line);
	mtx_hub = alloc_mtx(num_cmd, shell);
	// print_matrix(mtx_hub[0]);
	// print_matrix(mtx_hub[1]);
	// print_matrix(mtx_hub[2]);
	free_matrix(shell->mtx_line);
	i = 0;
	j = num_cmd - 1;
	shell->i = 0;
	// printf("num_cmd: %d\n", num_cmd);
	while (i < num_cmd)
	{
		printf("j: %d\n", j);
		if (pipe(fd) == -1)
			return (-1);
		id = fork();
		if (id == -1)
			return (-1);
		else if (id == 0)
		{
			if (j > 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			else if (j == 0)
			{
				// dup2(0, STDIN_FILENO);
				dup2(output, STDOUT_FILENO);
			}
			shell->mtx_line = matrix_dup(mtx_hub[i]);
			if (check_commands(shell->mtx_line[0], shell) == 1)
			{
				i = 0;
				while (mtx_hub[i])
				{
					free_matrix(mtx_hub[i]);
					i++;
				}
				free(mtx_hub);
				exit(1);
				return (1);
			}
			free_matrix(shell->mtx_line);
		}
		else
		{
			if (j > 0)
			{
				dup2(fd[0], STDIN_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			else if (j == 0)
			{
				dup2(input, STDIN_FILENO);
				dup2(output, STDOUT_FILENO);
			}
		}
		j--;
		i++;
	}
	while (wait(NULL) > 0)
		;
	i = 0;
	while (mtx_hub[i])
	{
		free_matrix(mtx_hub[i]);
		i++;
	}
	free(mtx_hub);
	return (0);
}

