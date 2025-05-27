/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:51:47 by cazerini          #+#    #+#             */
/*   Updated: 2025/05/27 14:52:02 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	if_close_child(char *tmp, int fd)
{
	ft_putstr_fd("shell: ", 2);
	ft_putstr_fd(tmp, 2);
	ft_putstr_fd(": is a directory\n", 2);
	close(fd);
	free(tmp);
	correct_exit(126);
}
