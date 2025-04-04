/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:55:44 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/04 10:55:11 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_there_in_env(t_program *shell, int len, char **env, int *flag)
{
	int		i;
	char	*dup;

	i = 0;
	if (shell->export_arg[len - 2] == '+')
	{
		(*flag) = 1;
		dup = remove_plus(shell->export_arg);
		len--;
	}
	else
		dup = ft_strdup(shell->export_arg);
	// printf("sono str di len %c\n", dup[len - 1]);
	if (ft_isalnum(dup[len - 2]) != 1 && dup[len - 2] != '+')
		return (free(dup), -2);
	while (env[i])
	{
		if (ft_strncmp(env[i], dup, len) == 0)
			return (free(dup), i);
		i++;
	}
	free(dup);
	return (-1);
}

char	*remove_plus(char *old_str)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = (char *)malloc(sizeof(char) * ft_strlen(old_str));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (old_str[i])
	{
		if (old_str[i] == '+')
			i++;
		else
		{
			new_str[j] = old_str[i];
			i++;
			j++;
		}
	}
	new_str[j] = '\0';
	printf("new_str: %s\n", new_str);
	return (new_str);
}
