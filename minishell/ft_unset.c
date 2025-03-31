/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:12:01 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/31 18:28:38 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_unset(t_program *shell)
{
	char	*str;
	char	*arg;
	char	**env_tmp;
	int		k;
	int		j;

	k = 0;
	j = 0;
	str = NULL;
	arg = NULL;
	if (shell->mtx_line[shell->i + 1] == NULL)
		return ;
	//tocca sapere se ce un dolalero
	if (check_dollar(shell->mtx_line[shell->i + 1]) == 1)
		arg = split_dollar(shell->mtx_line[shell->i + 1], shell);
	else
	{
		while (j < matrix_len(shell->env))
		{
			if (ft_strncmp(shell->env[j], shell->mtx_line[shell->i + 1], ft_strlen(shell->mtx_line[shell->i + 1])) == 0)
			{
				arg = ft_strdup(shell->env[j]);
				break ;	
			}
			j++;
		}	
	}
	//parsing arg (printf errore)
	//mi raccomando e' importante
	j = 0;
	if (arg != NULL)
	{
		env_tmp = (char **)ft_calloc(sizeof(char *), (matrix_len(shell->env) + 1));
		if (env_tmp == NULL)
			return ;
		while (shell->env[k])
		{
			if (ft_strncmp(shell->env[k], arg, ft_strlen(arg)) != 0)
			{
				env_tmp[j] = ft_strdup(shell->env[k]); 
				j++;
			}
			k++;
		}
		env_tmp[j] = NULL;
		free_matrix(shell->env);
		shell->env = matrix_dup(env_tmp);
		free_matrix(env_tmp);
		if (arg != NULL)
			free(arg);
	}
}


// copiata da modificare
char	*search_env_and_allocate(char *env_str, t_program *shell)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (shell->env[i])
	{
		//DEVE ESSERE SICUROP IL CHECK DAJE
		if (ft_strncmp(shell->env[i], env_str, ft_strlen(env_str)) == 0 /* && \
			shell->env[i][ft_strlen(env_str) + 1] == '=' */)
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
	if (add_str != NULL)
	{
		tmp = new_str;
		new_str = ft_strjoin(new_str, add_str);
		free(add_str);
		free(tmp);
	}
	return (new_str);
}

char	*split_dollar(char *old_str, t_program *shell)
{
	char	*new_str;
	char	**mtx;
	int		i;
	int		flag;
	char	*tmp;

	mtx = NULL;
	new_str = NULL;
	if (old_str[0] == '$')
		flag = 1;
	else
		flag = 0;
	mtx = ft_split(old_str, '$');
	if (mtx == NULL)
		return (NULL);
	i = 0;
	while (mtx[i])
	{
		if (!(flag == 1 && i == 0))
		{
			tmp = mtx[i];
			mtx[i] = expansion_variable(mtx[i], shell);
			if (mtx[i] == NULL)
				return (free_matrix(mtx), NULL);
			free(tmp);
		}
		i++;
	}
	i = 1;
	new_str = ft_strdup(mtx[0]);
	while (mtx[i])
	{
		if (mtx[i] != NULL)
		{
			tmp = new_str;
			new_str = ft_strjoin(new_str, mtx[i]);
			free(tmp);
		}	
		i++;
	}
	free_matrix(mtx);
	printf("E CORRETTO: %s\n", new_str);
	return (new_str);
}
