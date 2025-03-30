/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_command_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:30:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/30 19:25:12 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char *str;

	str = getenv("OLDPWD");
	printf("%s\n", str);
	return (0);
}

int	ft_env(t_program *shell)
{
	shell->i = 0;

	while (shell->env[shell->i])
	{
		printf("%s\n", shell->env[shell->i]);
		shell->i++;
	}
	return (0);
}

void	ft_exit(t_program *shell)
{
	printf("exit\n");
	free_matrix(shell->mtx_line);
	exit(0);
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
	int		i;
	int		j;
	int		len;
	char	*new_str;
	char	*tmp;

	new_str = NULL;
	if (check_dollar(old_str) == 0)
		return (NULL);
	i = 0;
	while (old_str[i])
	{
		if (old_str[i] == '$')
		{
			i++;
			if (old_str[i] == '\0')
			{
				printf("bash: unset: `%s': not a valid identifier", old_str);
				return (NULL);
			}
			j = i;
			len = 0;
			while (old_str[i] && (ft_isalnum(old_str[i]) == 1))
			{
				len++;
				i++;
			}
			new_str = ft_substr(old_str, j, len);
			if (new_str == NULL)
				return (NULL);
			if (new_str != NULL)
			{
				tmp = new_str;
				new_str = ft_strjoin(new_str, search_env_and_allocate(old_str, shell));
				free(tmp);
			}
			else
				new_str = search_env_and_allocate(old_str, shell);
		}
		else
		{
			if (new_str != NULL)
			{
				tmp = new_str;
				new_str = ft_strjoin(new_str, &old_str[i]);
				free(tmp);
			}
			else
				new_str = &old_str[i];
			i++;
		}
	}
	return (new_str);
}

// unset $OLDPWD
// bash: unset: `/nfs/homes/cazerini/42/minishell': not a valid identifier
void	ft_unset(t_program *shell)
{
	char	*str;
	char	**env_tmp;
	int		k;
	int		j;

	k = 0;
	j = 0;
	//str = NULL;
	if (shell->mtx_line[shell->i + 1] == NULL)
		return ;
	str = expansion_variable(shell->mtx_line[shell->i + 1], shell);
	printf("str: %s\n", str);
	if (str == NULL)
	{
		while (j < matrix_len(shell->env))
		{
			if (ft_strncmp(shell->env[j], shell->mtx_line[shell->i + 1], ft_strlen(shell->mtx_line[shell->i + 1])) == 0)
			{
				str = ft_strdup(shell->env[j]);
				break ;	
			}
			j++;
		}	
	}
	j = 0;
	if (str != NULL)
	{
		env_tmp = (char **)ft_calloc(sizeof(char *), (matrix_len(shell->env) + 1));
		if (env_tmp == NULL)
			return ;
		while (shell->env[k])
		{
			if (ft_strncmp(shell->env[k], shell->mtx_line[shell->i + 1], ft_strlen(shell->mtx_line[shell->i + 1])) != 0)
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
		if (str != NULL)
			free(str);
	}
}
