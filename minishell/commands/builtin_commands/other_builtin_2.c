/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_builtin_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:17:19 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/04 13:26:11 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(void)
{
	char	*buffer;

	buffer = getcwd(NULL, 4096);
	if (!buffer)
		return (1);
	printf("%s\n", buffer);
	free(buffer);
	return (0);
}
