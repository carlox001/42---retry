/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:21:55 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/01 16:41:26 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//make re && clear && valgrind --leak-check=full --show-leak-kinds=all --suppressions=supp.supp ./minishell


//things to do:
// 1: parsing del comando
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

void	print_directory(t_program *shell)
{
	
	if (ft_strlen(shell->pwd) < ft_strlen(shell->home_path))
		printf("shell:%s", shell->pwd);
	else
	{
		if (shell->curr_dir)
			printf("shell:~%s", shell->curr_dir);
		else
			printf("shell:~");
	}
	
}


int	initialize(t_program *shell)
{
	shell->exit_code = 0;

	shell->pwd = ft_strdup(getenv("PWD"));
	shell->home_path = ft_strdup(getenv("HOME"));
	shell->curr_dir = ft_substr(shell->pwd, ft_strlen(shell->home_path), \
		(ft_strlen(shell->pwd) - ft_strlen(shell->home_path)));
	return (0);
}


void	free_all(t_program *shell)
{
	if (shell->mtx_line != NULL)
		free_matrix(shell->mtx_line);
	if (shell->env != NULL)
		free_matrix(shell->env);
	free(shell->pwd);
	free(shell->home_path);
	free(shell->curr_dir);
}

int	main_core(t_program *shell)
{
	char	*str;
	int		flag;

	if (initialize(shell) == 1)
		return (1);
	while (1)
	{
		shell->mtx_line = NULL;
		print_directory(shell);
		str = readline("$ ");
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
