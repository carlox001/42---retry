/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:46:04 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/23 19:06:44 by sfiorini         ###   ########.fr       */
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
