/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:41:20 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/17 18:53:15 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_here_doc(t_program *shell, char **mtx)
{
	int		i;
	int		fd;
	char	*file;
	char	*tmp;

	i = counter_in_out('<', mtx);
	if (i == 0)
		return (0);
	i = 0;
	shell->num_hd = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == '<' && mtx[i][1] == '<')
		{
			tmp = ft_itoa(shell->num_hd);
			file = ft_strjoin(".here_doc_", tmp);
			fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0777);
			free(tmp);
			if (fd == -1)
			{
				free(file);
				return (1);
			}
			i++;
			write_in_file(fd, mtx[i]);
			close(fd);
			free(file);
			shell->num_hd++;
		}
		i++;
	}
	return (shell->num_hd);
}

void	write_in_file(int fd, char *limiter)
{
	char	*str;

	while (1)
	{
		str = get_next_line_bonus(0);
		if (ft_strncmp(str, limiter, ft_strlen(limiter)) == 0)
		{
			free(str);
			break ;
		}
		ft_putstr_fd(str, fd);
		free(str);
	}
}
