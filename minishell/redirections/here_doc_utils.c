/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:46:04 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/27 12:38:13 by sfiorini         ###   ########.fr       */
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
