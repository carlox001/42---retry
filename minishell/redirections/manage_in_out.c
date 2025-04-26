/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_in_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:54:56 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/23 15:31:15 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	counter_in_out(char c, char **mtx)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == c)
			counter++;
		i++;
	}
	return (counter);
}

char	**realloc_without_redir(char **mtx, int k, char c)
{
	int		i;
	int		j;
	char	**new_mtx;

	new_mtx = (char **)malloc(sizeof(char *) * (matrix_len(mtx) - (k * 2) + 1));
	if (new_mtx == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (mtx[i])
	{
		if (mtx[i][0] == c)
			i += 2;
		else if (mtx[i] != NULL)
		{
			new_mtx[j] = ft_strdup(mtx[i]);
			i++;
			j++;
		}
	}
	new_mtx[j] = NULL;
	return (new_mtx);
}
