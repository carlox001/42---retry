/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:07:29 by apeero            #+#    #+#             */
/*   Updated: 2024/11/22 15:07:30 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	i = ft_strlen(s);
	write(fd, s, i);
	return (i);
}
