/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:35 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/23 17:00:13 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error_cringe(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	close_child(int flag, t_program *shell, char ****mtx_hub)
{
	free_matrix_pointer(*mtx_hub);
	if (flag == 1)
		free_all(shell, 1);
	close(shell->input);
	close(shell->output);
	if (shell->num_cmd != 1 && flag == 1)
		correct_exit(shell->exit_code);
	correct_exit(127);
}

void	correct_exit(int code)
{
	close(1);
	close(0);
	exit(code);
}
