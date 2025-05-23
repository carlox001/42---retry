/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:12:01 by cazerini          #+#    #+#             */
/*   Updated: 2025/05/23 15:36:34 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	ft_unset(t_program *shell)
{
	char	*arg;
	int		k;
	int		j;
	int		l;

	arg = NULL;
	if (shell->mtx_line[shell->i + 1] == NULL)
		return ;
	if (unset_parsing(shell) == 1)
		return ;
	l = 1;
	while (shell->mtx_line[shell->i + l] != NULL)
	{
		k = 0;
		j = 0;
		if (check_dollar(shell->mtx_line[shell->i + l]) == 1)
			arg = split_dollar(shell->mtx_line[shell->i + l], shell);
		else
			arg = search_unset(shell, l);
		if (arg != NULL)
			arg_treatment(shell, arg, k, j);
		l++;
	}
	shell->i += l;
}

char	*search_env_and_allocate(char *env_str, t_program *shell)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], env_str, ft_strlen(env_str)) == 0)
		{
			while (shell->env[i][j] != '=' && shell->env[i][j])
				j++;
			j++;
			new_str = ft_substr(shell->env[i], j, ft_strlen(shell->env[i]));
		}
		i++;
	}
	return (new_str);
}

// cambiare print errori, fare controllo dopo aver preso l'argomento
char	*expansion_variable(char *old_str, t_program *shell)
{
	char	*new_str;
	char	*add_str;
	char	*tmp;
	int		i;

	add_str = NULL;
	i = 0;
	while (old_str[i])
	{
		if (old_str[i] != '_' && (ft_isalnum(old_str[i]) == 0))
			break ;
		i++;
	}
	if ((int)ft_strlen(old_str) > i)
	{
		tmp = ft_substr(old_str, 0, i);
		add_str = ft_substr(old_str, i, (int)ft_strlen(old_str));
		new_str = search_env_and_allocate(tmp, shell);
		free(tmp);
	}
	else
		new_str = search_env_and_allocate(old_str, shell);
	expansion_variable_end(&new_str, add_str);
	return (new_str);
}

void	expansion_variable_end(char **new_str, char *add_str)
{
	char	*tmp;

	if (add_str != NULL)
	{
		tmp = *new_str;
		*new_str = ft_strjoin(*new_str, add_str);
		free(add_str);
		free(tmp);
	}
}
