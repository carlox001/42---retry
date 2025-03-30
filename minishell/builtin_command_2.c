/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_command_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:30:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/30 18:37:08 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// sistematre piu' quotes all'inizio
// controllare che ci siano solo ed esculivamente caratteri prima dell'uguale _ va bene
// facciamo echo per echo $?


//gestire parsing meglio imbecilli (es: ''ciao'')
// export non prende se ci sono solo numeri prima dell'uguale


char	*remove_external_quotes(char *old_str)
{
	int		count_left;
	int		count_right;
	int		i;
	int		j;
	char	*new_str;
	int		len;

	i = 0;
	count_left = 0;
	count_right = 0;
	while (old_str[i] == '\'' || old_str[i] == '"')
	{
		i++;
		count_left++;
	}
	i = ft_strlen(old_str) - 1;
	while (old_str[i] == '\'' || old_str[i] == '"')
	{
		i--;
		count_right++;
	}
	if (count_left == 0 || count_right == 0)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(old_str) + 1 - (count_left + count_right)));
	if (new_str == NULL)
		return (NULL);
	i = count_left;
	j = 0;
	len = (int)ft_strlen(old_str);
	while (i < (len - count_right))
	{
		new_str[j] = old_str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

void	ft_echo(t_program *shell)
{
	char	*str;
	char	*str2;

	// echo_parsing
	if (shell->mtx_line[shell->i + 1] == NULL)
	{
		printf("\n");
		return ;
	}
	str = ft_strdup(shell->mtx_line[shell->i + 1]);
	str2 = remove_external_quotes(str);
	if (str2 == NULL)
		str2 = ft_strdup(str);
	free(str);
	if (check_dollar(str2) == 1)
		exec_dollar(str2, shell);
	else if (str2)
		printf("%s\n", str2);	
	free(str2);
	shell->i++;
}

// 1: trova dollar
// 0: non trova
int	check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

void	exec_dollar(char *str, t_program *shell)
{
	int		i;
	int		j;
	int		len;
	char	*env_str;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] == '\0')
			{
				printf("$");
				return ;
			}
			j = i;
			while (str[i] && (ft_isalnum(str[i]) == 1))
			{
				len++;
				i++;
			}
			env_str = ft_substr(str, j, len);
			if (env_str == NULL)
				return ;
			search_env(env_str, shell);
		}
		else
		{
			printf("%c", str[i]);
			i++;
		}
	}
	printf("\n");
}

void	search_env(char *env_str, t_program *shell)
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
			printf("%s", new_str);
			free(new_str);
		}
		i++;
	}
}
