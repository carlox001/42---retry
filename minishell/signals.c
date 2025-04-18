/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:39:26 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/17 18:39:42 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sig_handler_child(int sig)
{

	//free all
	// if (sig == SIGSEGV)
	// {
	// 	printf("\n");
	// 	exit(0);
	// }
	//aggiungere exit code 130 e sul control \ inserire 0
	if (sig == SIGINT)
	{
		signals = SIGINT;
		// exit(130);
		printf("\n");
		// rl_on_new_line();
		rl_redisplay();
	}
}


void sig_handler(int sig)
{

	//free all
	// if (sig == SIGSEGV)
	// {
	// 	printf("\n");
	// 	exit(0);
	// }
	//aggiungere exit code 130 e sul control \ inserire 0
	if (sig == SIGINT)
	{
		signals = SIGINT;
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
		// printf("ronadlo\n\n\n\n");
	}
}
