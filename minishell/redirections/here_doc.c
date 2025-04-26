/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:41:20 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/25 19:29:33 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_here_doc(t_program *shell, char **mtx)
{
	int		i;
	int		fd;
	char	*file;

	file = NULL;
	shell->num_hd = 0;
	i = counter_in_out('<', mtx);
	if (i == 0)
		return (0);
	i = 0;

	int id;
	id =fork();
	if (id == 0)
	{
		while (mtx[i])
		{
			if (mtx[i][0] == '<' && mtx[i][1] == '<')
			{
				fd = open_here_doc_core(&i, &file, &shell->num_hd);
				if (fd == -1)
					return (-1);
				write_in_file(fd, mtx[i], shell);
				close(fd);
				free(file);
				shell->num_hd++;
			}
			i++;
		}
		free_all(shell, 0);
		exit(shell->num_hd);
	}
	else
	{
		waitpid(id, &shell->num_hd, 0);
		shell->num_hd /= 256;
	}
	return (shell->num_hd);
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
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		str = readline("> ");
		if (write_in_file_check(&str, &flag, shell, limiter) == 1)
			break ;
		if (ft_strncmp(str, limiter, ft_strlen(limiter)) == 0)
		{
			free(str);
			break ;
		}
		if (check_dollar(str) == 1)
			exec_dollar(str, shell, fd);
		else
			ft_putstr_fd(str, fd);
		free(str);
	}
	set_hd_g_signals(0);
}

int	write_in_file_check(char **str, int *flag, t_program *shell, char *limiter)
{
	if (*str == NULL)
	{
		if (g_signals == 0)
		{
			printf("shell: warning: here-document delimited \
by end-of-file (wanted `%s')\n", limiter);
				*str = ft_strdup(limiter);
			}
		}
		if (g_signals == SIGINT)
		{
			g_signals = 0;
			*flag = 1;
			shell->exit_code = 130;
			free(*str);
			return (1);
		}
		return (0);
	}

void	close_here_doc(t_program *shell)
{
	int		i;
	char	*num;
	char	*file;

	i = 0;
	while (i < shell->num_hd)
	{
		num = ft_itoa(i);
		file = ft_strjoin(".here_doc_", num);
		unlink(file);
		free(file);
		free(num);
		i++;
	}
	shell->num_hd = 0;
}
