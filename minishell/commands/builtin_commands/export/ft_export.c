/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:52:42 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/10 17:04:42 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

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
	while (shell->cpy_exp[i][j])
	{
		while (shell->cpy_exp[i][j] && shell->cpy_exp[i][j] != '=')
		{
			printf("%c", shell->cpy_exp[i][j]);
			j++;
		}
		if (shell->cpy_exp[i][j] == '=')
		{
			j++;
			printf("=\"");
			while (shell->cpy_exp[i][j])
			{
				printf("%c", shell->cpy_exp[i][j]);
				j++;
			}
			printf("\"\n");
		}
		else
			printf("\n");
	}
}

int	there_is_a_plus(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

void	update_plus(char **str)
{
	char	*tmp;

	tmp = *str;
	*str = remove_plus(*str);
	free(tmp);
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
		ft_putstr_fd("shell: export: `", 2);
		ft_putstr_fd(err, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		shell->exit_code = 1;
		free(err);
	}
	if (value >= 0)
	{
		printf("lo faccio\n");
		change_export_value(shell, i, value, str);
	}
	else
	{
		if (there_is_a_plus(str) == 1)
			update_plus(&str);
		if (realloc_env(shell, str) == 1)
			return ;
	}
}
