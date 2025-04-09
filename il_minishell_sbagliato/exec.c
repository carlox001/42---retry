/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:53:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/09 19:05:29 by cazerini         ###   ########.fr       */
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
	// printf("num_commands: %d\n", num_commands);
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
	if (dup_mtx[0] != NULL)
	{
		mtx_hub[j] = matrix_dup(dup_mtx);
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
	int		j;
	int		num_cmd;
	char	***mtx_hub;

	shell->output = dup(STDOUT_FILENO);
	shell->input = dup(STDIN_FILENO);
	num_cmd = count_commands(shell->mtx_line);
	mtx_hub = alloc_mtx(num_cmd, shell);
	free_matrix(shell->mtx_line);
	j = num_cmd - 1;
	shell->i = 0;
	if (exec_core(shell, j, num_cmd, mtx_hub) == 1)
		return (1);
	close(shell->output);
	close(shell->input);
	while (wait(NULL) > 0)
		;
	free_matrix_pointer(mtx_hub);
	return (0);
}

// int	redirections(t_program *shell, char ***mtx_hub)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (mtx_hub[i])
// 	{
// 		while (mtx_hub[i][j])
// 		{
// 			if (mtx_hub[i][j] == '<')
				
// 			j++;
// 		}
// 		i++;
// 	}
	

// 	return (0);
// }

int	exec_core(t_program *shell, int j, int num_cmd, char ***mtx_hub)
{
	int		i;
	int		id;

	i = 0;
	while (i < num_cmd)
	{
		if (pipe(shell->fd) == -1)
			return (-1);
		id = fork();
		if (id == -1)
			return (-1);
		else if (id == 0)
			child(shell, i, j, mtx_hub);
		else
			father(shell, j);
		j--;
		i++;
	}
	return (0);
}

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
	int	i;
	int	j;

	printf("allocazione: %d\n", counter_in_out('<', mtx));
	shell->in = (int *)malloc(sizeof(int) * counter_in_out('<', mtx));
	if (shell->in == NULL)
		return (1);	
	i = 0;
	j = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == '<')
		{
			i++;
			shell->in[j] = open(mtx[i], O_RDONLY);
			if (shell->in[j] == -1)
			{
				printf("mannaggia bosgna scrivere l'errore");
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

	printf("allocazione: %d\n", counter_in_out('>', mtx));
	shell->out = (int *)malloc(sizeof(int) * counter_in_out('>', mtx));
	if (shell->out == NULL)
		return (1);	
	i = 0;
	j = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == '>')
		{
			i++;
			shell->out[j] = open(mtx[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (shell->out[j] == -1)
			{
				printf("mannaggia bosgna scrivere l'errore");
			}
			j++;
		}
		i++;
	}
	return (j);
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
			printf("mtx[i]: %s\n", mtx[i]);
			new_mtx[j] = ft_strdup(mtx[i]);
			i++;
			j++;
		}
	}
	new_mtx[j] = NULL;
	return (new_mtx);
}

void	child(t_program *shell, int i, int num_cmd, char ***mtx_hub)
{
	int		l;
	int		k;
	int		p[2];
	int		id2;
	char	*str;
	char	**tmp;
	int		check;

	k = open_files_in(mtx_hub[i], shell);
	if (k == -1)
		return ;
	if (k > 0)
	{
		tmp = realloc_without_redir(mtx_hub[i], k, '<');
		if (tmp == NULL)
			return ;
		free_matrix(mtx_hub[i]);
		mtx_hub[i] = matrix_dup(tmp);
		free_matrix(tmp);
		l = 0;
		dup2(shell->fd[0], STDIN_FILENO);
		dup2(shell->fd[1], STDOUT_FILENO);
		while (l < k)
		{
			while (1)
			{
				str = get_next_line_bonus(shell->in[l]);
				if (str == NULL)
					break ;
				printf("%s",str);
				free(str);
			}
			l++;
		}
		// printf("%s", str);
		k = 0;
	}
	k = open_files_out(mtx_hub[i], shell);
	if (k == -1)
		return ;
	if (k > 0)
	{
		tmp = realloc_without_redir(mtx_hub[i], k, '>');
		if (tmp == NULL)
			return ;
		free_matrix(mtx_hub[i]);
		mtx_hub[i] = matrix_dup(tmp);
		free_matrix(tmp);
	}
	shell->mtx_line = matrix_dup(mtx_hub[i]);
	
	if (pipe(p) == -1)
		return ;
	id2 = fork();
	if (id2 < 0)
		return ;
	if (id2 == 0)
	{
		dup2(shell->fd[0], STDIN_FILENO);
		dup2(p[1], STDOUT_FILENO);			
		if (check_commands(shell->mtx_line[0], shell) == 1)
		{
			free_matrix_pointer(mtx_hub);
			// exit(1);
		}
	}
	else
	{
		wait(NULL);
		dup2(p[0], STDIN_FILENO);
		printf("num_cmd %d\n", num_cmd);
		if (num_cmd == 0)
		{
			printf("k: %d\n", k);
			if (k > 0)
			{
				
				l = 0;
				while (l < k)
				{
					dup2(shell->out[l], STDOUT_FILENO);
					close(shell->out[l]);
					check = 0;
					while (1)
					{
						str = malloc(100);
						check = read(p[0], str, 100);
						if (check < 100)
						{
							write(1, str, check);
							free(str);
							break ;
							
						}
						write(1, str, check);
						free(str);
					}
					close(p[0]);
					l++;
				}
			}
			else
			{
				printf("ciao\n");
				// dup2(shell->output, STDOUT_FILENO);
				check = 0;
				while (1)
				{
					str = malloc(100);
					check = read(p[0], str, 100);
					if (check < 100)
					{
						write(1, str, check);
						free(str);
						break ;
						
					}
					write(1, str, check);
					free(str);
				}
				close(p[0]);
			}
			close_all_files(shell->fd, shell->output, shell->input);
		}
		dup2(shell->output, STDOUT_FILENO);
		// printf("ci arrivo\n");
		exit(1);
	}
	// printf("entro\n");
}

void	father(t_program *shell, int num_cmd)
{
	if (num_cmd > 0)
		close_fds(shell->fd, 1, shell->input);
	else if (num_cmd == 0)
		close_fds(shell->fd, 0, shell->input);
	exit(1);
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

void	close_fds(int *fd, int flag, int input)
{
	if (flag == 1)
		dup2(fd[0], STDIN_FILENO);
	else
		dup2(input, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	close_all_files(int *fd, int output, int input)
{
	close(fd[0]);
	close(fd[1]);
	close(output);
	close(input);
}
