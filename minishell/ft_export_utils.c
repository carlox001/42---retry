/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:55:44 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/29 15:56:57 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_there_in_env(t_program *shell, int len, char *str, int *flag)
{
	int		i;
	char	*dup;

	i = 0;
	if (str[len - 2] == '+')
	{
		(*flag) = 1;
		dup = remove_plus(str);
		len--;
	}
	else
		dup = ft_strdup(str);
	// printf("sono str di len %c\n", dup[len - 1]);
	if (ft_isalnum(dup[len - 2]) != 1 && dup[len - 2] != '+')
		return (free(dup), -2);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], dup, len) == 0)
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
