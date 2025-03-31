/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:28 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/31 15:28:54 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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

int	count_args(char **mtx, int i)
{
	int	len;

	len = 0;
	while (mtx[i] && only_operator(mtx[i]) == 0)
	{
		len++;
		i++;
	}
	return (len);
}

int	check_nflag(char *str, t_program *shell)
{
	if (ft_strncmp(str, "-n", 2) == 0 && ft_strlen(str) == 2)
	{
		shell->i++;
		return (1);
	}
	return (0);
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
