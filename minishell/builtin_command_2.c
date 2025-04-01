/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_command_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:30:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/01 18:21:15 by cazerini         ###   ########.fr       */
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
	shell->curr_dir = ft_substr(shell->pwd, ft_strlen(shell->home_path), \
	(ft_strlen(shell->pwd) - ft_strlen(shell->home_path)));
}


int	only_backslash(char *str)
{
	int	i;

	i = 2;
	while (str[i])
	{
		if (str[i] != '/')
			return (1);
		i++;
	}
	return (0);
}

void	ft_cd(t_program *shell)
{
	if (shell->mtx_line[shell->i + 1] == NULL)
		only_cd(shell);
	else if (shell->mtx_line[shell->i + 2] != NULL)
	{
		printf("shell: cd: too many arguments\n");
		shell->exit_code = 1;
	}
	else if (no_char(shell->mtx_line[shell->i + 1]) == 0)
	{
		cd_no_char(shell->mtx_line[shell->i + 1], shell);
		shell->exit_code = 0;
		return ;
	}
/* 	else if (parsing_cd(shell->mtx_line[shell->i + 1]) == 1)
	{
		printf("bash: cd: %s: No such file or directory\n", shell->mtx_line[shell->i + 1]);
		return	
	} */
/* 	else if (ft_strncmp(shell->mtx_line[shell->i + 1], \
		"..", 2) == 0 ) && (only_backslash(shell->mtx_line[shell->i + 1]) == 1)
		cd_back(shell);
	else if (ft_strncmp(shell->mtx_line[shell->i + 1], \
		"/.", 2) == 0 && ft_strlen(shell->mtx_line[shell->i + 1]) == 2)
		cd_root(shell); */
	
	// else if (only_)
	
}

void	cd_no_char(char *str, t_program *shell)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == '.' && str[i + 1] != '\0')
		{
			i += 2;
			counter++;
			if (str[i] == '.' && str[i] != '\0')
			{
				printf("bash: cd: %s: No such file or directory\n", str);
				shell->exit_code = 1;
				return ;
			}
			if (str[i] == '\0')
				i--;
		}
		i++;
	}
	if (str[0] == '/')
	{
		cd_root(shell);
		return ;
	}
	while (counter > 0)
	{
		cd_back(shell);
		counter--;
	}
}


int	no_char(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '/')
			return (1);
		i++;
	}
	return (0);
}
void	only_cd(t_program *shell)
{
	free(shell->pwd);
	shell->pwd = ft_strdup(shell->home_path);
	free(shell->curr_dir);
	shell->curr_dir = ft_strdup("");
	if (chdir(shell->home_path) == -1)
		return ;
}

void	cd_root(t_program *shell)
{
	free(shell->pwd);
	shell->pwd = ft_strdup("/");
	free(shell->curr_dir);
	shell->curr_dir = ft_strdup("/");
	if (chdir(shell->pwd) == -1)
		return ;
}

void	cd_back(t_program *shell)
{
	char	*path;
	int		i;

	if (shell->pwd[0] == '/' && shell->pwd[1] == '\0')
		return	;
	i = ft_strlen(shell->pwd) - 1;
	while (shell->pwd[i])
	{
		if (shell->pwd[i] == '/')
			break ;
		i--;
	}
	if (i == 0)
		i++;
	path = ft_substr(shell->pwd, 0, i);
	if (chdir(path) == -1)
		return (free(path));
	free(shell->pwd);
	shell->pwd = ft_strdup(path);
	free(path);
	refresh_directory(shell);	
}
