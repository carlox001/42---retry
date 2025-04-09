/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:04:58 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/05 14:26:39 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	quotes_core(char *str, t_program *shell, int *i_p)
{
	shell->i_p = (*i_p);
	if (double_quote(str, shell) == 1)
		return (1);
	else if (single_quote(str, shell) == 1)
		return (1);
	return (0);
}

int	double_quote(char *str, t_program *shell)
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
		if (alloc_quote(shell, flag, str, '"') == 1)
			return (1);
	}
	return (0);
}

//separa in funzioni e bella

int	single_quote(char *str, t_program *shell)
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
		if (alloc_quote(shell, flag, str, '\'') == 1)
			return (1);
	}
	return (0);
}


int	alloc_quote(t_program *shell, int flag, char *str, char q)
{
	if (flag == 1)
	{
		shell->mtx_line[shell->j] = ft_substr(str, shell->i_p, (shell->i - shell->i_p + 1));
		if (shell->mtx_line[shell->j] == NULL)
			return (1);
		shell->j++;
	}
	else if ((shell->i - shell->i_p) != 0)
	{
		if (str[shell->i] == q && str[shell->i - 1] == q)
			shell->i_p -= 2;
		shell->mtx_line[shell->j] = ft_substr(str, shell->i_p, (shell->i - shell->i_p));
		if (shell->mtx_line[shell->j] == NULL)
			return (1);
		shell->j++;
	}
	shell->i_p = shell->i;
	return (0);
}
