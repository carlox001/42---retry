/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:43:40 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/17 18:43:58 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*print_directory(t_program *shell)
{
	char	*str;
	char	*tmp;

	if (shell->home_path != NULL)
	{
		if (ft_strlen(shell->pwd) < ft_strlen(shell->home_path))
			str = ft_strjoin("shell:", shell->pwd);
		else
		{
			if (shell->curr_dir)
				str = ft_strjoin("shell:~", shell->curr_dir);
			else
				str = ft_strdup("shell:~");
		}
		tmp = str;
		str = ft_strjoin(str, "$ ");
		free(tmp);
	}
	else
	{
		str = ft_strjoin("shell:", shell->pwd);
		tmp = str;
		str = ft_strjoin(str, "$ ");
		free(tmp);
	}
	return (str);
}


int	initialize(t_program *shell)
{
	char	*str;

	shell->exit_code = 0;
	signals = 0;
	// if (!str)
		// return (1);
	str = getcwd(NULL, 1000);
	
	shell->pwd = ft_strdup(str);
	shell->old_pwd = ft_strdup(str);
	free(str);
	str = getenv("HOME");
	if (str == NULL)
	{
		shell->home_path = NULL;
		shell->curr_dir = ft_strdup(shell->pwd);	
	}
	else
	{
		shell->home_path = ft_strdup(getenv("HOME"));
		shell->curr_dir = ft_substr(shell->pwd, ft_strlen(shell->home_path), \
			(ft_strlen(shell->pwd) - ft_strlen(shell->home_path)));
	}
	return (0);
}


void	free_all(t_program *shell, int flag)
{
	if (flag == 0)
	{
		if (shell->mtx_line != NULL)
			free_matrix(shell->mtx_line);
	}
	if (shell->env != NULL)
		free_matrix(shell->env);
	if (shell->pwd != NULL)
		free(shell->pwd);
	if (shell->home_path != NULL)
		free(shell->home_path);
	if (shell->curr_dir != NULL)
		free(shell->curr_dir);
	if (shell->old_pwd != NULL)	
		free(shell->old_pwd);
}
