/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:21:55 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/05 16:05:57 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//make re && clear && valgrind --leak-check=full --show-leak-kinds=all --suppressions=supp.supp ./minishell

// inseriamo le guardie alle allocazione

int	signals = 0;

void sig_handler(int sig)
{

	//free all
	// if (sig == SIGSEGV)
	// {
	// 	printf("\n");
	// 	exit(0);
	// }
	//aggiungere exit code 130 e sul control \ inserire 0
	if (sig == SIGINT)
	{
		signals = SIGINT;
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

//things done
int	main(int ac, char **av, char **env)
{
	t_program	shell;

	(void)ac;
	(void)av;
	// shell = (t_program *)malloc(sizeof(t_program) * 1);
	shell.env = matrix_dup(env);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	if (main_core(&shell) == 1)
	{
		printf("error\n");
		return (1);
	}
	// clear_history();
	return (0);
}
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


void	free_all(t_program *shell)
{
	if (shell->mtx_line != NULL)
		free_matrix(shell->mtx_line);
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

int	main_core(t_program *shell)
{
	char	*str;
	int		flag;
	char	*print_str;

	if (initialize(shell) == 1)
		return (1);
	while (1)
	{
		print_str = print_directory(shell);
		shell->mtx_line = NULL;
		str = readline(print_str);
		free(print_str);
		if (!str)
			return (printf("exit\n"), free_all(shell), 0);
		if (signals == SIGINT)
			shell->exit_code = 130;
		add_history(str);
		flag = parsing(str, shell);
		free(str);
		if (flag != 0)
		{
			if (exec(shell) == 1)
				return (free_all(shell), 1);
			if (flag == 1)
				free_matrix(shell->mtx_line);
		}
	}
	return (0);
}
