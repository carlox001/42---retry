/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:45:00 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/06 18:24:46 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// invalid read con ""

int	parsing(char *str, t_program *shell)
{
	// char	**commands;
	// aggiungere gli exit code
	if (str[0] == '\0')
		return (0);
	if (str[ft_strlen(str) - 1] == '>' || str[ft_strlen(str) - 1] == '<')
	{
		printf("shell: syntax error near unexpected token `newline'\n");
		shell->exit_code = 2;
		return (0);
	}
	if (check_quotes(str) == 1)
	{
		printf("shell: syntax error: open quotes\n");
		shell->exit_code = 0;
		return (0);
	}
	if (check_operators(str, shell) == 1)
	{
		printf("shell: syntax error: operators error\n");
		shell->exit_code = 0;
		return (0);
	}
	if (matrix_handler(str, shell) == 1)
	{
		printf("Error\nfailed allocation\n");
		shell->exit_code = 0;
		return (0);
	}
	// print_matrix(shell->mtx_line);
	return (1);
}

int	print_parsing_errors(int flag, t_program *shell)
{
	if (flag == 1)
		printf("shell: parse error near `|'\n");
	if (flag == 2)
		printf("shell: parse error near `>'\n");
	if (flag == 3)
		printf("shell: parse error near `<'\n");
	if (flag == 4)
		printf("shell: parse error near `\\n'\n");
	if (flag == 5)
		printf("shell: parse error near `||'\n");
	if (flag == 6)
		printf("shell: syntax error\n");
	shell->exit_code = 1;
	return (1);
}

int	only_operator(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (ft_strlen(str) == 2)
	{
		if (str[0] == '<' && str[1] == '<')
			return (4);
		if (str[0] == '>' && str[1] == '>')
			return (4);
	}
	while (str[i])
	{
		if (str[i] == '|')
			flag = 1;
		if (str[i] == '>')
			flag = 2;
		if (str[i] == '<')
			flag = 3;
		else if (str[i] != '|' && str[i] != '>' && str[i] != '<' && str[i] != ' ' && str[i] != '\0')
			return (0);
		i++;
	}
	return (flag);
}

int	near_operators(char *str)
{
	int	i;
	int	op;

	i = 0;
	while (str[i])
	{
		op = 0;
		if (str[i] == '|' || str[i] == '<' || str[i] == '>')
		{
			op++;
			i++;
			while ((str[i] == '|' || str[i] == '<' || str[i] == '>' || str[i] == ' ') &&  str[i])
			{
				if (str[i] != ' ')
				{
					if (str[i] == '>')
					{
						i++;
						op++;
						if (str[i] == '>')
							i++;
					}
					else if (str[i] == '<')
					{
						i++;
						op++;
						if (str[i] == '<')
							i++;
					}
					else
					{
						op++;
						i++;
					}
				}
				else
					i++;
			}
			if (op > 2)
				return (1);
		}
		i++;
	}
	return (0);
}

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
				if (!(str[i] == '>' && str[i - 1] == '>') && !(str[i] == '<' && str[i - 1] == '<'))
					return (1);
			}
		}
		i++;
	}
	return (0);
}


int	check_operators(char *str, t_program *shell)
{
	int	i;
	int	check;

	i = 0;
	check = only_operator(str);
	if (check != 0)
	{
		print_parsing_errors(check, shell);
		return (1);
	}
	if (str[0] == '|' || str[ft_strlen(str) - 1] == '|')
	{
		print_parsing_errors(1, shell);
		return (1);
	}
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|')
		{
			print_parsing_errors(5, shell);
			return (1);
		}
		i++;
	}
	if (double_operators(str) == 1)
	{
		print_parsing_errors(6, shell);
		return (1);
	}
	
	return (0);
}

int	check_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				i++;
			if (str[i] == '\0')
				return (1);
		}
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}
