/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:41:20 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/21 12:31:27 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_here_doc(t_program *shell, char **mtx)
{
	int		i;
	int		id;

	shell->num_hd = 0;
	shell->check_hd = 0;
	i = counter_in_out('<', mtx);
	if (i == 0)
		return (0);
	i = 0;
	id = fork();
	if (id == 0)
	{
		if (open_here_doc_while(&i, shell, mtx) == -1)
			return (-1);
	}
	else
	{
		if (else_here_doc(shell, id) == -2)
			return (-2);
	}
	return (shell->num_hd);
}

int	open_here_doc_while(int *i, t_program *shell, char **mtx)
{
	int		fd;
	char	*file;
	char	*tmp;

	file = NULL;
	while (mtx[*i])
	{
		if (mtx[*i][0] == '<' && mtx[*i][1] == '<')
		{
			fd = open_here_doc_core(i, &file, &shell->num_hd);
			if (fd == -1)
				return (-1);
			tmp = remove_couple_quotes(mtx[*i]);
			write_in_file(fd, tmp, shell);
			close(fd);
			free(file);
			free(tmp);
			shell->num_hd++;
		}
		(*i)++;
	}
	free_all(shell, 0);
	correct_exit(shell->num_hd);
	return (0);
}

int	open_here_doc_core(int *i, char **file, int *num_hd)
{
	int		fd;
	char	*tmp;

	tmp = ft_itoa(*num_hd);
	*file = ft_strjoin(".here_doc_", tmp);
	fd = open(*file, O_CREAT | O_TRUNC | O_RDWR, 0777);
	free(tmp);
	if (fd == -1)
	{
		free(*file);
		return (-1);
	}
	(*i)++;
	return (fd);
}

void	write_in_file(int fd, char *limiter, t_program *shell)
{
	char	*str;
	int		flag;

	set_hd_g_signals(1);
	while (1)
	{
		str = readline("> ");
		if (write_in_file_check(&str, &flag, limiter, shell) == 1)
			break ;
		if (ft_strncmp(str, limiter, ft_strlen(limiter)) == 0 && \
			ft_strlen(limiter) == ft_strlen(str))
		{
			free(str);
			break ;
		}
		if (check_dollar(str) == 1)
			exec_dollar(str, shell, fd);
		else
			ft_putstr_fd(str, fd);
		write(fd, "\n", 1);
		free(str);
	}
	set_hd_g_signals(0);
}

int	write_in_file_check(char **str, int *flag, char *limiter, t_program *shell)
{
	if (*str == NULL)
	{
		if (g_signals == 0)
		{
			ft_putstr_fd("shell: warning: here-document delimited \
by end-of-file (wanted `", 2);
			ft_putstr_fd(limiter, 2);
			ft_putstr_fd("')\n", 2);
			*str = ft_strdup(limiter);
			shell->check_hd++;
		}
	}
	if (g_signals == SIGINT)
	{
		*flag = 1;
		free(*str);
		return (1);
	}
	return (0);
}
