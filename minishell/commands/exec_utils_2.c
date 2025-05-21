/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:13:11 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/19 14:46:01 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	increments(int *i, int *j)
{
	(*j)++;
	(*i)++;
}

void	set_exec_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	update_counter_exec(int *j, int *i)
{
	(*j)--;
	(*i)++;
}
