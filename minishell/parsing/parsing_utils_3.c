/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:04:25 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/09 11:35:37 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_new_matrix(char **mtx, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (mtx != NULL)
			count++;
		i++;
	}
	return (count);
}

int	only_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '$')
			return (0);
		i++;
	}
	return (1);
}

int	print_parsing_errors(int flag, t_program *shell)
{
	if (flag == 1)
		ft_putstr_fd("shell: parse error near `|'\n", 2);
	if (flag == 2)
		ft_putstr_fd("shell: parse error near `>'\n", 2);
	if (flag == 3)
		ft_putstr_fd("shell: parse error near `<'\n", 2);
	if (flag == 4)
		ft_putstr_fd("shell: parse error near `\\n'\n", 2);
	if (flag == 5)
		ft_putstr_fd("shell: parse error near `||'\n", 2);
	if (flag == 6)
		ft_putstr_fd("shell: syntax error\n", 2);
	shell->exit_code = 2;
	return (1);
}
