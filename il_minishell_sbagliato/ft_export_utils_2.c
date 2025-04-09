/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:16:08 by cazerini          #+#    #+#             */
/*   Updated: 2025/04/04 18:30:26 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_export(t_program *shell)
{
	int	i;
	int	j;

	i = 0;
	if (shell->mtx_line[shell->i + 1] == NULL)
	{
		while (shell->env[i])
		{
			j = 0;
			print_export_env(shell, i, j);
			i++;
		}
		return (1);
	}
	return (0);
}

// esegue del parsing aggiuntivo peril comando export
int	export_parsing(t_program *shell)
{
	char	*str;

	// printf("shell->mtx_line[shell->i + 1]: %s\n", shell->mtx_line[shell->i + 1]);
	str = ft_strdup(shell->mtx_line[shell->i + 1]);
	if (export_parsing_2(shell, str) == -1)
		return (-1);
	if (export_parsing_quote(str) == 1)
	{
		printf("shell: export: `%s': not a valid identifier 1\n", str);
		shell->exit_code = 1;
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int	export_parsing_2(t_program *shell, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
	{
		if (str[i] == '+' && str[i + 1] == '=')
			break ;
		if (ft_isalnum(str[i]) != 1  && str[i] != '_' && \
			str[i] != '\'' && str[i] != '"')
		{
			printf("shell: export: `%s': not a valid identifier 2\n", str);
			free(str);
			shell->exit_code = 1;
			return (-1);
		}
		i++;
	}
	return (0);
}

int	export_parsing_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '"')
		{
			if (export_quote(str, &i, '"', '\'') == 1)
				return (1);
		}
		else if (str[i] == '\'')
		{
			if (export_quote(str, &i, '\'', '"') == 1)
				return (1);
		}
		else
			i++;
	}
	return (0);
}

int	export_quote(char *str, int *i, char q1, char q2)
{
	while (str[(*i)] && (str[(*i)] != '=' || str[(*i)] != q1))
	{
		if (str[(*i)] == q2)
			return (1);
		(*i)++;
	}
	return (0);
}
