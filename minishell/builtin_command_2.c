/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_command_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:30:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/31 19:08:25 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* char *args[2];

args[0] = "ls";
args[1] = NULL;
execve("/bin/ls", args, NULL); */

void	refresh_directory(t_program *shell)
{
	free(shell->curr_dir);
	shell->curr_dir = ft_substr(shell->pwd, ft_strlen(shell->user_path), \
	(ft_strlen(shell->pwd) - ft_strlen(shell->user_path)));
}

void	ft_cd(t_program *shell)
{
	int		i;
	char	*path;

	i = ft_strlen(shell->pwd) - 1;
	while (shell->pwd[i])
	{
		if (shell->pwd[i] == '/')
			break ;
		i--;
	}
	path = ft_substr(shell->pwd, 0, i);
	if (chdir(path) == -1)
		return ;
	free(shell->pwd);
	shell->pwd = ft_strdup(path);
	free(path);
	refresh_directory(shell);

}