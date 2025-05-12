/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:36:38 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/10 17:30:40 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	double_operators(char *str)
{
	int		i;
	char	a;

	if (near_operators(str) == 1)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '<' || str[i] == '>')
		{
			a = str[i];
			i++;
			while (str[i] && str[i] == ' ')
				i++;
			if ((str[i] == '|' || str[i] == '<' || str[i] == '>') && a != '|')
			{
				if (!(str[i] == '>' && str[i - 1] == '>') && \
				!(str[i] == '<' && str[i - 1] == '<') && \
				!(str[i] == '>' && str[i - 1] == '<'))
					return (1);
			}
		}
		skip(str, &i);
	}
	return (0);
}

void	skip(char *str, int *i)
{
	if (str[*i] != '\0')
		(*i)++;
}

int	triple_operator(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>' && str[i + 1] && \
			str[i + 1] == '>' && str[i + 2] && \
			str[i + 2] == '>')
			return (1);
		if (str[i] == '<' && str[i + 1] && \
			str[i + 1] == '<' && str[i + 2] && \
			str[i + 2] == '<')
			return (1);
		i++;
	}
	return (0);
}

int	check_operators(char *str, t_program *shell)
{
	int	i;
	int	check;

	i = 0;
	check = only_operator(str, shell);
	if (check != 0)
		return (print_parsing_errors(check, shell), 1);
	if (str[0] == '|' || str[ft_strlen(str) - 1] == '|')
	{
		print_parsing_errors(1, shell);
		return (1);
	}
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|')
			return (print_parsing_errors(5, shell), 1);
		i++;
	}
	if (double_operators(str) == 1)
		return (print_parsing_errors(6, shell), 1);
	if (triple_operator(str) == 1)
		return (print_parsing_errors(6, shell), 1);
	return (0);
}
