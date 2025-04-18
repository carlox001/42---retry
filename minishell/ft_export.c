/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:52:42 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/18 10:55:23 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//problema in matrix handler quando si va a scrivere tipo : export d
// famo gli exit code
void	ft_export(t_program *shell)
{
	int		i;
	int		value;
	int		j;
	char	*str;
	char	*dup;

	if (only_export(shell) == 1)
		return ;
	if (export_parsing(shell) == 1)
		return ;
	j = 1;
	while (shell->mtx_line[shell->i + j])
	{
		i = 0;
		dup = ft_strdup(shell->mtx_line[shell->i + j]);
		str = remove_all_quotes(dup);
		free(dup);
		value = 0;
		i = export_cicle(str);
		export_core(shell, value, i, str);
		j++;
	}
	shell->i += j;
}

int	export_cicle(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			break ;
		}
		if (str[i] == '>' || str[i] == '<')
		{
			dup = str;
			str = ft_substr(str, 0, i);
			free(dup);
			break ;
		}
		else
			i++;
	}
	return (i);
}

int	exist_in_env(char *str, t_program *shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	shell->equal = 0;
	while (str[j])
	{
		if (str[j] == '=')
		{
			shell->equal = 1;
			break ;
		}
		j++;
	}
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], str, j) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	print_export_env(t_program *shell, int i, int j)
{
	printf("declare -x ");
	while (shell->env[i][j])
	{
		while (shell->env[i][j] && shell->env[i][j] != '=')
		{
			printf("%c", shell->env[i][j]);
			j++;
		}
		if (shell->env[i][j] == '=')
		{
			j++;
			printf("=\"");
			while (shell->env[i][j])
			{
				printf("%c", shell->env[i][j]);
				j++;
			}
			printf("\"\n");
		}
		else
			printf("\n");
	}
}

void	export_core(t_program *shell, int value, int i, char *str)
{
	char	*err;

	shell->flag = 0;
	value = is_there_in_env(shell, i, str, &shell->flag);
	if (value == -3)
		return (free(str));
	if (value == -2)
	{
		err = ft_substr(str, 0, i);
		printf("shell: export: `%s': not a valid identifier\n", err);
		shell->exit_code = 1;
		free(err);
		return ;
	}
	if (value >= 0)
		change_export_value(shell, i, value, str);
	else
	{
		if (realloc_env(shell, str) == 1)
			return ;
	}
}
