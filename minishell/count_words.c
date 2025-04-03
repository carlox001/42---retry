/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:49:48 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/29 15:51:22 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// se inserisci degli operatori 
// attacati non funziona il count es (sfsdf|>sd)

// Questa funzione conta il numero di 
// token e li restituisce
int	count_words(char *str, t_program *shell)
{
	int words;
	int flag;

	shell->len = (int)ft_strlen(str);
	shell->i = 0;
	flag = 0;
	words = 0;
	while (shell->i < shell->len)
	{
		while (str[shell->i] == ' ' && str[shell->i])
			shell->i++;
		count_char(str, shell, &words, &flag);
		count_quotes(str, shell, &words);
		count_operators(str, shell, &words);
		shell->i++;
	}
	return (words);
}

void	count_char(char *str, t_program *shell, int *words, int *flag)
{
	while (((str[shell->i] >=  33 && str[shell->i] < 127) && str[shell->i] && \
			(str[shell->i] != '|' && str[shell->i] != '>' && str[shell->i] != '<' && \
			str[shell->i] != '"' && str[shell->i] != '\'')) && (str[shell->i]))					
	{
		shell->i++;
		if ((*flag) == 0)
		{
			(*flag) = 1;
			(*words)++;
		}
	}
	(*flag) = 0;
}

void	count_quotes(char *str, t_program *shell, int *words)
{
	if (str[shell->i] == '"')
	{
		shell->i++;
		while (str[shell->i] && str[shell->i] != '"')
			shell->i++;
		if (shell->i < shell->len)
			shell->i++;
		(*words)++;
	}
	if (str[shell->i] == '\'')
	{
		shell->i++;
		while (str[shell->i] && str[shell->i] != '\'')
			shell->i++;
		if (shell->i < shell->len)
			shell->i++;
		(*words)++;
	}
}

void	count_operators(char *str, t_program *shell, int *words)
{
	if (str[shell->i] == '|' || str[shell->i] == '>' || str[shell->i] == '<')
	{
		if ((str[shell->i] == '>' && str[shell->i + 1] == '>') || \
			(str[shell->i] == '<' && str[shell->i + 1] == '<'))
		{
			if (shell->i + 1 < shell->len)
				shell->i = shell->i + 2;
		}
		else if (shell->i < shell->len)
			shell->i++;
		(*words)++;
	}
	// if (shell->i < shell->len)
	// 	shell->i++;
}
	
