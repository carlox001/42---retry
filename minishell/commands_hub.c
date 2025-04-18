/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_hub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:32:04 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/17 19:23:14 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_commands(char *cmd, t_program *shell, int k, char ***mtx_hub) 
{
	int	check;

	if (k != -1)
		close_in_out(shell->out, k, 1);
	check = check_builtin(cmd, shell);
	if (check == 1)
	{
		free_matrix(shell->mtx_line);
		return (1);
	}
	else if (exec_non_builtin(shell, 0, mtx_hub) == 1)
		return (1);
	return (0);
}

int	check_builtin(char *cmd, t_program *shell)
{
	if (ft_strncmp(cmd, "echo", 4) == 0 && ft_strlen(cmd) == 4)
		return (ft_echo(shell), 1);
	else if (ft_strncmp(cmd, "pwd", 3) == 0 && ft_strlen(cmd) == 3)
		return (ft_pwd(), 1);
	else if (ft_strncmp(cmd, "env", 3) == 0 && ft_strlen(cmd) == 3)
		return (ft_env(shell), 1);
	else if (ft_strncmp(cmd, "cd", 2) == 0 && ft_strlen(cmd) == 2)
		return (ft_cd(shell), 1);
	else if (ft_strncmp(cmd, "export", 6) == 0 && ft_strlen(cmd) == 6)
		return (ft_export(shell), 1);
	else if (ft_strncmp(cmd, "unset", 5) == 0 && ft_strlen(cmd) == 5)
		return (ft_unset(shell), 1);
	else if (ft_strncmp(cmd, "exit", 4) == 0 && ft_strlen(cmd) == 4)
		return (ft_exit(shell), 1);
	return (0);
}

int	exec_non_builtin(t_program *shell, int index, char ***mtx_hub)
{
	char	*path;
	char	**full_cmd;


	shell->tmp = shell->mtx_line[index];
	shell->mtx_line[index] = remove_all_quotes(shell->mtx_line[index]);
	free(shell->tmp);
	path = path_find(shell->env, shell->mtx_line[index]);
	if (path == NULL)
	{
		shell->exit_code = 127;
		shell->i = matrix_len(shell->mtx_line);
		free(path);
		shell->exit_code = 127;
		free_all(shell, 0);
		return (1);
	}
	full_cmd = get_full_cmd(shell);
	printf("messi\n");
	// signal(SIGINT, sig_handler_child);
	if (execve(path, full_cmd, shell->env) == -1)
	{
		free(path);
		free_matrix(full_cmd);
		shell->exit_code = 127;
		free_all(shell, 1);
		free_matrix_pointer(mtx_hub);
		free(shell->mtx_line);
		exit(2);
		return (1);
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
		// printf("sno il valore ahhaha: %s\n", shell->mtx_line[shell->i + len]);
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
		// printf("");
		full_cmd[i] = remove_all_quotes(shell->mtx_line[i]);
		// if (shell->mtx_line[i][0] == '\"' || shell->mtx_line[i][0] == '\'')
		// {
		// 	if (shell->mtx_line[i][0] == '\"')
		// 		full_cmd[i] = remove_external_quotes(shell->mtx_line[i], '\"');
		// 	else
		// 		full_cmd[i] = remove_external_quotes(shell->mtx_line[i], '\'');
		// }
		// else
		// 	full_cmd[i] = ft_strdup(shell->mtx_line[i]);
		i++;
	}
	full_cmd[i] = NULL;
	return (full_cmd);
}
