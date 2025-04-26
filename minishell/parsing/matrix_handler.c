/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:22:24 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/26 17:10:13 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//segfaulta cmd: shell->mtx_line[shell->i + 1]


// alloca la matrice della riga che ci passano
int	matrix_handler(char *str, t_program *shell)
{
	shell->words = count_words(str, shell);
	if (shell->words == 0)
	{
		printf("%s: comamnd not found\n", str);
		shell->exit_code = 127;
		return (2);
	}
	shell->mtx_line = (char **)ft_calloc(sizeof(char *), (shell->words + 1));
	if (shell->mtx_line == NULL)
		return (1);
	shell->i = 0;
	shell->j = 0;
	shell->i_p = 0;
	while (shell->i < shell->len)
	{
		if (matrix_handler_core(str, shell, &(shell->i), &(shell->j)) == 1)
			return (1);
		if (str[shell->i] == '|' || \
			str[shell->i] == '>' || str[shell->i] == '<')
		{
			if (operators_allocation(str, shell, shell->i, shell->j) == 1)
				return (1);
			operators_core(str, shell, &(shell->i), &(shell->j));
			shell->j++;
		}
		else if (shell->i < shell->len)
			shell->i++;
		shell->i_p = shell->i;
	}	
	shell->mtx_line[shell->words] = NULL;
	return (0);
}

// guarda se ci sono quotes nella parola
int	quotes_in_word(char *str, int *i)
{
	if (str[*i] == '"' || str[*i] == '\'')
	{
		if (*i != 0 && str[*i + 1] != ' ' && str[*i - 1] != ' ' && str[*i + 1] != '\0')
		{
			if (str[*i + 1] == '\'' || str[*i + 1] == '\"')
				(*i)++;
			(*i)++;
			return (1);
		}
		else
			return (0);
	}
	else
	{
		if ((str[*i] >= 33 && str[*i] < 127) && str[*i] && \
		(str[*i] == '|' && str[*i] == '>' && str[*i] == '<'))
			return (1);
		else
			return (0);
	}
}

int	matrix_handler_core(char *str, t_program *shell, int *i, int *j)
{
	int	flag;

	while (str[*i] == ' ' && str[*i])
	{
		(*i)++;
		shell->i_p++;
	}
	flag = 1;
	while (flag == 1)
	{
		while (isvalid(str, *i) == 1)
			(*i)++;	
		flag = quotes_in_word(str, i);
	}
	if (*i > 0 && (str[*i - 1] == '\"' || str[*i - 1] == '\''))
		(*i)++;
	while (isvalid(str, *i) == 1)
			(*i)++;
	if (((*i - shell->i_p) != 0) && (str[*i] != '"' && str[*i] != '\''))
	{
		shell->mtx_line[*j] = ft_substr(str, shell->i_p, (*i - shell->i_p));
		if (shell->mtx_line[*j] == NULL)
			return (1);
		(*j)++;
	}
	if (quotes_core(str, shell, &(shell->i_p)) == 1)
		return (1);
	return (0);
}


void	operators_core(char *str, t_program *shell, int *i, int *j)
{
	if (str[*i] == '>' && str[*i + 1] == '>')
	{
		shell->mtx_line[*j][0] = '>';
		shell->mtx_line[*j][1] = '>';
		shell->mtx_line[*j][2] = '\0';
		if (shell->i + 1 < shell->len)
			*i = *i + 2; 
	}
	else if (str[*i] == '<' && str[*i + 1] == '<')
	{
		shell->mtx_line[*j][0] = '<';
		shell->mtx_line[*j][1] = '<';
		shell->mtx_line[*j][2] = '\0';
		if (shell->i + 1 < shell->len)
			*i = *i + 2;
	}
	else if (str[*i] == '<' && str[*i + 1] == '>')
	{
		shell->mtx_line[*j][0] = '<';
		shell->mtx_line[*j][1] = '>';
		shell->mtx_line[*j][2] = '\0';
		if (shell->i + 1 < shell->len)
			*i = *i + 2;
	}
	else
	{
		shell->mtx_line[*j][0] = str[*i];
		shell->mtx_line[*j][1] = '\0';
		if (shell->i < shell->len)
			(*i)++;
	}
}

int	operators_allocation(char *str, t_program *shell, int i, int j)
{
	if ((str[i] == '>' && str[i + 1] == '>' ) || \
		(str[i] == '<' && str[i + 1] == '<' ) || \
		(str[i] == '<' && str[i + 1] == '>'))

		shell->mtx_line[j] = (char *)malloc(sizeof(char) * 3);
	else
		shell->mtx_line[j] = (char *)malloc(sizeof(char) * 2);
	if (!shell->mtx_line[j])
		return (1);
	return (0);
}
