/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:39:26 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/23 17:49:24 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_handler_child(int sig)
{
	if (sig == SIGINT)
	{
		g_signals = SIGINT;
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		g_signals = SIGQUIT;
		printf("Quit (core dumped)\n");
		rl_redisplay();
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signals = SIGINT;
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		g_signals = SIGQUIT;
		// printf("\n");
		// rl_on_new_line();
		rl_redisplay();
	}
}


void	sig_handler_hd(int sig)
{
	// char	*str;

	// str = NULL;
	if (sig == SIGINT)
	{
		g_signals = SIGINT;
		close(0);
		// exit(130);
	}
	if (sig == SIGQUIT)
	{
		g_signals = SIGQUIT;
		// close(0);
		rl_redisplay();
	}
}
