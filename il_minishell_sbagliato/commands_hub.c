/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_hub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:04 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/09 19:03:24 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_commands(char *cmd, t_program *shell) 
{
	int	check;

	check = check_builtin(cmd, shell);
	if (check == 1)
		return (1);
	if (check == 2)
		return (0);
	else if (exec_non_builtin(cmd, shell) == 1)
		return (1);
	return (0);
}

int	check_builtin(char *cmd, t_program *shell)
{
	if (ft_strncmp(cmd, "echo", 4) == 0 && ft_strlen(cmd) == 4)
		return (ft_echo(shell), 1);
	if (ft_strncmp(cmd, "cd", 2) == 0 && ft_strlen(cmd) == 2)
		return (ft_cd(shell), 1);
	else if (ft_strncmp(cmd, "pwd", 3) == 0 && ft_strlen(cmd) == 3)
		return (ft_pwd(), 1);
	else if (ft_strncmp(cmd, "export", 6) == 0 && ft_strlen(cmd) == 6)
		return (ft_export(shell), 1);
	else if (ft_strncmp(cmd, "unset", 5) == 0 && ft_strlen(cmd) == 5)
		return (ft_unset(shell), 1);
	else if (ft_strncmp(cmd, "env", 3) == 0 && ft_strlen(cmd) == 3)
		return (ft_env(shell), 1);
	else if (ft_strncmp(cmd, "exit", 4) == 0 && ft_strlen(cmd) == 4)
		return (ft_exit(shell), 1);
	return (0);
}

int	exec_non_builtin(char *cmd, t_program *shell)
{
	char	*path;
	char	**full_cmd;
	int		id;

	if (is_there_a_backslash(cmd) == 1)
		path = ft_strdup(cmd);
	else
	{
		path = path_find(shell->env, cmd);
		if (path == NULL)
		{
			printf("%s: command not found\n", cmd);
			shell->exit_code = 127;
			shell->i = matrix_len(shell->mtx_line);
			free(path);
			shell->exit_code = 127;
			free_all(shell);
			return (1);
		}
	}
	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
	{
		full_cmd = get_full_cmd(shell);
		if (execve(path, full_cmd, shell->env) == -1)
		{
			free(path);
			free_matrix(full_cmd);
			shell->exit_code = 127;
			free_all(shell);
			exit(2);
			return (1);
		}
	}
	return (0);
}

char	*getpath(char **envp)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			path = envp[i];
		i++;
	}
	return (path);
}

char	*path_find(char **envp, char *command)
{
	int		i;
	char	*path;
	char	**paths;
	char	*path_joined;

	if (command[0] == '/')
		return (command);
	i = 0;
	path = getpath(envp);
	if (path == NULL)
		return (NULL);
	paths = ft_split(&path[5], ':');
	while (paths[i])
	{
		path_joined = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_joined, command);
		if (access(path, F_OK) == 0)
			return (free(path_joined), free_matrix(paths), path);
		free(path);
		free(path_joined);
		i++;
	}
	free_matrix(paths);
	return (NULL);
}
	
char	**get_full_cmd(t_program *shell)
{
	int		len;
	int		i;
	char	**full_cmd;

	len = 0;
	shell->i = 0;
	// printf("i: %d\n", shell->i);
	// printf("mtx_line: %s\n", shell->mtx_line[shell->i]);
	// printf("len: %d\n", len);
	while (shell->mtx_line[shell->i + len])
	{
		if (shell->mtx_line[shell->i + len][0] != '<' && \
			shell->mtx_line[shell->i + len][0] != '>' && \
			shell->mtx_line[shell->i + len][0] != '|')
			len++;
		else
			break ;
	}
	shell->i += len;
	full_cmd = (char **)malloc(sizeof(char *) * (len + 1));
	if (full_cmd == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		full_cmd[i] = ft_strdup(shell->mtx_line[i]);
		i++;
	}
	full_cmd[i] = NULL;
	return (full_cmd);
}

	
int	is_there_a_backslash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}