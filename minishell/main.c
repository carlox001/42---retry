/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:21:55 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/17 18:44:02 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//make re && clear && valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=supp.supp --quiet ./minishell
//make re && clear && valgrind --suppressions=supp.supp --leak-check=full --track-fds=yes --trace-children=yes ./minishell
//make re && clear && valgrind --leak-check=full --show-leak-kinds=all --suppressions=supp.supp --quiet ./minishell

// inseriamo le guardie alle allocazione
// controllare gli exit code e scrivere commenti su come funzionano le funzioni
// file errori

//things done
int	main(int ac, char **av, char **env)
{
	t_program	shell;

	(void)ac;
	(void)av;
	// shell = (t_program *)malloc(sizeof(t_program) * 1);
	shell.fork_id = -2;
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
	char	*print_str;

	if (initialize(shell) == 1)
		return (1);
	while (1)
	{
		signal(SIGINT, sig_handler);
		print_str = print_directory(shell);
		shell->mtx_line = NULL;
		// printf("\n\n\n\n\n\n\nfork_id: %d\n\n\n", shell->fork_id);
		// if (shell->fork_id == 0)
		// {
			
		// 	exit(130);
		// }
		str = readline(print_str);
		free(print_str);
		if (!str)
			return (printf("exit\n"), free_all(shell, 0), 0);
		if (signals == SIGINT)
			shell->exit_code = 130;
		add_history(str);
		flag = parsing(str, shell);
		free(str);
		if (flag != 0)
		{
			
			// int id;
			// printf("cappuccino assassino\n");
			// id = fork();
			// if (id == 0)
			// {
			signal(SIGINT, sig_handler_child);
			if (open_here_doc(shell, shell->mtx_line) == -1)
				return (free_all(shell, 0), 1);
				// exit(0);
			// }
			// else
			// {
			// 	printf("francesco totti\n");
			// 	signal(SIGINT, SIG_IGN);
			// 	waitpid(id, &shell->exit_code, 0);
			// 	printf("exit_code: %d\n", shell->exit_code);
			// 	// signal(SIGINT, sig_handler);
			// }
			if (exec(shell) == 1)
				return (free_all(shell, 0), 1);
			
			
			
			// if (open_here_doc(shell, shell->mtx_line) == -1)
				// return (free_all(shell, 0), 1);
		}
		// if (shell->fork_id == 0)
		// {
			
		// 	exit(130);
		// }
	}
	return (0);
}
