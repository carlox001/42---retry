/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:04:58 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/29 17:45:21 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	quotes_core(char *str, t_program *shell, int *i_p)
{
	if (double_quote(str, shell, i_p) == 1)
		return (1);
	else if (single_quote(str, shell, i_p) == 1)
		return (1);
	return (0);
}

int	double_quote(char *str, t_program *shell, int *i_p)
{
	int	flag;

	flag = 0;
	if (str[shell->i] == '"')
	{
		shell->i++;

		while (str[shell->i] && str[shell->i] != '"')
		{
			flag = 1;
			shell->i++;
		}
		// if (shell->i < shell->len)
		// 	shell->i++;
		if (flag == 1)
		{
			shell->mtx_line[shell->j] = ft_substr(str, *(i_p), (shell->i - *(i_p) + 1));
			if (shell->mtx_line[shell->j] == NULL)
				return (1);
			shell->j++;
		}
		*(i_p) = shell->i;
	}
	return (0);
}

int	single_quote(char *str, t_program *shell, int *i_p)
{
	int	flag;

	flag = 0;
	if (str[shell->i] == '\'')
	{
		shell->i++;
		while (str[shell->i] && str[shell->i] != '\'')
		{
			flag = 1;
			shell->i++;
		}
		// if (shell->i < shell->len)
		// 	shell->i++;
		if (flag == 1)
		{
			shell->mtx_line[shell->j] = ft_substr(str, *(i_p), (shell->i - *(i_p) + 1));
			if (shell->mtx_line[shell->j] == NULL)
				return (1);
			shell->j++;
		}
		*(i_p) = shell->i;
	}
	return (0);
}