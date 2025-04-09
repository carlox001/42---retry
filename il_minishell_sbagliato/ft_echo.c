/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:28 by cazerini          #+#    #+#             */
/*   Updated: 2025/04/05 17:59:55 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// sistematre piu' quotes all'inizio
// controllare che ci siano solo ed esculivamente caratteri prima dell'uguale _ va bene
// facciamo echo per echo $?

//gestire parsing meglio imbecilli (es: ''ciao'')
// export non prende se ci sono solo numeri prima dell'uguale

void	ft_echo(t_program *shell)
{
	char	*str;
	char	*str2;
	int		i;
	int		len;

	// echo_parsing
	if (shell->mtx_line[shell->i + 1] == NULL)
	{
		printf("\n");
		return ;
	}
	shell->nflag = check_nflag(shell->mtx_line[shell->i + 1], shell);
	len = count_args(shell->mtx_line, shell->i + 1);
	i = 0;
	// printf();
	while (i < len)
	{
		str = ft_strdup(shell->mtx_line[shell->i + 1]);
		str2 = remove_external_quotes(str, '"');
		if (str2 == NULL)
			str2 = ft_strdup(str);
		free(str);
		if (str2[0] != '>')
		{
			if (check_dollar(str2) == 1)
				exec_dollar(str2, shell, i, len);
			else if (str2)
			{
				if (i != len)
					printf("%s ", str2);
				else
					printf("%s", str2);
			}
		}
		else
		{
			i++;
			shell->i++;
			if (shell->mtx_line[shell->i + 1] != NULL)
			{
				i++;
				shell->i++;
			}
		}
		free(str2);
		i++;
		shell->i++;
	}
	//metti il check sul meno n qui
	if (shell->nflag != 1)
		printf("\n");
}

void	exec_dollar(char *str, t_program *shell, int i2, int len2)
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
			else if (str[i] == '?')
			{
				printf("%d", shell->exit_code);
				i++;
			}
			else if (str[i] == '"' || str[i] == '\'')
				i++;
			else
			{
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
				free(env_str);
			}
		}
		else
		{
			if (str[i] == '"' || str[i] == '\'')
				i++;
			printf("%c", str[i]);
			if (str[i] != '\0')
				i++;
		}
	}
	if (i2 != len2)
		printf(" ");
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
		if (ft_strncmp(shell->env[i], env_str, ft_strlen(env_str)) == 0)
		{
			while (shell->env[i][j] != '=' && shell->env[i][j])
				j++;
			j++;
			new_str = ft_substr(shell->env[i], j, ft_strlen(shell->env[i]) - j);
			printf("%s", new_str);
			free(new_str);
		}
		i++;
	}
}
