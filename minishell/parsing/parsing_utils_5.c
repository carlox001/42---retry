/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:04:25 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/11 19:30:33 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_flag(int *flag_s, int *flag_d, char c)
{
	if (c == '\"')
	{
		if (*flag_d == 0)
			*flag_d = 1;
		else
			*flag_d = 0;
	}
	if (c == '\'' && *flag_d == 0)
	{
		if (*flag_s == 0)
			*flag_s = 1;
		else
			*flag_s = 0;
	}
}

int	check_pipe(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == '|' && mtx[i + 1][0] == '|')
			return (1);
		if (mtx[i] != NULL)
			i++;
	}
	return (0);
}
