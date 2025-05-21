/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:46:04 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/21 12:44:43 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_hd_g_signals(int flag)
{
	if (flag == 1)
	{
		signal(SIGQUIT, sig_handler_hd);
		signal(SIGINT, sig_handler_hd);
	}
	else
	{
		signal(SIGQUIT, sig_handler_child);
		signal(SIGINT, sig_handler);
	}
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

int	else_here_doc(t_program *shell, int id)
{
	waitpid(id, &shell->num_hd, 0);
	shell->num_hd /= 256;
	if (shell->num_hd == 255)
	{
		shell->exit_code = 0;
		return (-2);
	}
	if (g_signals == 2)
	{
		shell->exit_code = 130;
		close_here_doc(shell);
		return (-2);
	}
	return (0);
}

void	false_heredoc(t_program *shell, char *str)
{
	matrix_handler(str, shell);
	open_here_doc(shell, shell->mtx_line);
	close_here_doc(shell);
	free_matrix(shell->mtx_line);
}
