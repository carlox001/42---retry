/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:21:55 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/11 19:30:16 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// "$HOME"'$USER"*.c'" ' ' "'"$USER"$HOME'"''*.c'''"$USER

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
			else if (flag != -2 && main_core_2(shell) == 1)
				return (1);
			else if (flag == -2)
				free_matrix(shell->mtx_line);
		}
	}
	return (0);
}

int	main_core_2(t_program *shell)
{
	if (only_redir(shell->mtx_line) == 1)
	{
		shell->exit_code = 0;
		close_here_doc(shell);
	}
	else if (exec(shell) == 1)
		return (free_all(shell, 0), 1);
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
		return (printf("exit\n"), free_all(shell, 0), 1);
	printf("g_signals: %d\n", g_signals);
	if (g_signals == SIGINT)
	{
		g_signals = 0;
		shell->exit_code = 130;
	}
	if (g_signals == SIGQUIT)
	{
		g_signals = 0;
		shell->exit_code = 131;
	}
	if (*str[0] != '\0')
		add_history((*str));
	return (0);
}

int	only_redir(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == '<' || mtx[i][0] == '>')
			i += 2;
		else
			return (0);
	}
	free_matrix(mtx);
	return (1);
}
