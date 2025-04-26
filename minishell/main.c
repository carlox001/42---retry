/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:21:55 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/26 16:53:35 by cazerini         ###   ########.fr       */
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
	shell.fork_id = -2;
	shell.flag_in_operator = 0;
	shell.env = matrix_dup(env);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	if (main_core(&shell) == 1)
		return (1);
	return (0);
}

int	main_core(t_program *shell)
{
	char	*str;
	int		flag;

	if (initialize(shell) == 1)
		return (1);
	str = NULL;
	while (1)
	{
		if (readline_core(shell, &str) == 1)
			return (1);
		flag = parsing(str, shell);
		free(str);
		if (flag != 0)
		{
			signal(SIGINT, sig_handler_child);
			signal(SIGQUIT, sig_handler);
			flag = open_here_doc(shell, shell->mtx_line);
			if (flag == -1)
				return (free_all(shell, 0), 1);
			if (exec(shell) == 1)
				return (free_all(shell, 0), 1);
		}
	}
	return (0);
}

// esegue readline e aggiunge la stringa alla history
int	readline_core(t_program *shell, char **str)
{
	char	*print_str;

	signal(SIGINT, sig_handler);
	print_str = print_directory(shell);
	shell->mtx_line = NULL;
	*str = readline(print_str);
	free(print_str);
	if (!(*str))
	{
		//qui
		return (printf("exit\n"), free_all(shell, 0), 1);
	}
	if (g_signals == SIGINT)
	{
		g_signals = 0;
		shell->exit_code = 130;
	}
	add_history((*str));
	return (0);
}
