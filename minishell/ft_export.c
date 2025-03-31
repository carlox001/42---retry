/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:52:42 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/31 15:18:42 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//problema in matrix handler quando si va a scrivere tipo : export d
// famo gli exit code
void	ft_export(t_program *shell)
{
	char	*str;
	char	*dup;
	int		i;
	int		flag;
	int		value;

	if (only_export(shell) == 1)
		return ;
	i = 0;
	if (export_parsing(shell) == 1)
		return ;
	dup = ft_strdup(shell->mtx_line[shell->i + 1]);
	printf("dup: %s\n", dup);
	str = remove_all_quotes(dup);
	free(dup);
	value = 0;
	flag =  0;
	while (str[i] && flag == 0)
	{
		if (str[i] == '=')
			flag = 1;
		if (str[i] == '>' || str[i] == '<')
			break ;
		i++;
	}
	if (flag == 0)
		return (free(str));
	export_core(shell, value, i, str);
}

int	only_export(t_program *shell)
{
	int	i;

	i = 0;
	if (shell->mtx_line[shell->i + 1] == NULL)
	{
		while (shell->env[i])
		{
			printf("declare -x %s\n", shell->env[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

// esegue del parsing aggiuntivo peril comando export
int	export_parsing(t_program *shell)
{
	int		i;
	char	*str;

	
	// printf("shell->mtx_line[shell->i + 1]: %s\n", shell->mtx_line[shell->i + 1]);
	str = ft_strdup(shell->mtx_line[shell->i + 1]);
	i = 0;
	while (str[i] != '=' && str[i])
	{
		if (str[i] == '+' && str[i + 1] == '=')
			break ;
		if (ft_isalnum(str[i]) != 1  && str[i] != '_' && \
			str[i] != '\'' && str[i] != '"')
		{
			printf("shell: export: `%s': not a valid identifier\n", str);
			free(str);
			return (1);
		}
		i++;
	}
	if (export_parsing_quote(str) == 1)
	{
		printf("shell: export: `%s': not a valid identifier\n", str);
		free(str);
		return (1);
	}
	// if (i == ((int)ft_strlen(str) + 1)) //nn ho cpt
	// 	printf("culo\n");
	free(str);
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
			while (str[i] && (str[i] != '=' || str[i] != '"'))
			{
				if (str[i] == '\'')
					return (1);
				i++;
			}
		}
		else if (str[i] == '\'')
		{
			while (str[i] && (str[i] != '=' || str[i] != '\''))
			{
				if (str[i] == '"')
					return (1);
				i++;
			}
		}
		else
			i++;
	}
	return (0);
}

// il cuore della funzione export
void	export_core(t_program *shell, int value, int i, char *str)
{
	char	*err;

	shell->flag = 0;
	value = is_there_in_env(shell, i, str, &shell->flag);
	if (value == -2)
	{
		err = ft_substr(str, 0, i);
		printf("shell: export: `%s': not a valid identifier\n", err);
		free(err);
	}
	if (value >= 0)
		change_export_value(shell, i, value, str);
	else
	{
		if (realloc_env(shell, str) == 1)
			return ;
	}
}

// cambia il valore inserito all'interno 
// di env senza la riallocazione
void	change_export_value(t_program *shell, int i, int value, char *str)
{
	char	*dup2;
	char	*dup;

	if (shell->flag == 1)
	{
		dup = ft_strdup(shell->env[value]);
		free(shell->env[value]);
		dup2 = ft_substr(str, i, ft_strlen(str));
		shell->env[value] = ft_strjoin(dup, dup2);
		free(str);
		free(dup);
		free(dup2);
	}
	else
	{
		free(shell->env[value]);
		shell->env[value] = ft_strdup(str);
		free(str);
	}
}

// rialloca env poiche' la nuova stringa non esiste
int	realloc_env(t_program *shell, char *str)
{
	char	**mtx_dup;
	int		i;

	mtx_dup = matrix_dup(shell->env);
	if (mtx_dup == NULL)
		return (1);
	free_matrix(shell->env);
	shell->env = (char **)malloc(sizeof(char *) * (matrix_len(mtx_dup) + 2));
	if (shell->env == NULL)
		return (1);
	i = 0;
	while (mtx_dup[i])
	{
		shell->env[i] = ft_strdup(mtx_dup[i]);
		i++;
	}
	shell->env[i] = str;
	shell->env[i + 1] = NULL;
	free_matrix(mtx_dup);
	return (0);
}
