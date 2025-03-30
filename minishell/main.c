/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:21:55 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/28 10:44:24 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//make re && clear && valgrind --leak-check=full --show-leak-kinds=all --suppressions=supp.supp ./minishell


//things to do:
// 1: parsing del comando


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

int	main_core(t_program *shell)
{
	char	*str;
	int		flag;

	while (1)
	{
		str = readline("shell:~$ ");
		if (!str)
			return (printf("exit\n"), free_matrix(shell->env), 0);
		add_history(str);
		flag = parsing(str, shell);
		free(str);
		if (flag != 0)
		{
			if (exec(shell) == 1)
				return (1);
			if (flag == 1)
				free_matrix(shell->mtx_line);
		}			
	}
	return (0);
}
