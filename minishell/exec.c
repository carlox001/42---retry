/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:53:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/05 18:13:55 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec(t_program *shell)
{
	shell->i = 0;
	while (shell->i < matrix_len(shell->mtx_line))
	{
		if (check_commands(shell->mtx_line[shell->i], shell) == 1)
			return (1);
		shell->i++;
	}	
	return (0);
}
