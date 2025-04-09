/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:56:55 by sfiorini          #+#    #+#             */
/*   Updated: 2025/03/31 17:01:45 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		printf("i: %d |%s|\n", i, matrix[i]);
		i++;
	}
}

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	free_matrix(char **matrix)
{
	int	j;

	// if (matrix == NULL)
	// 	return ;
	j = 0;
	while (matrix[j])
	{
		free(matrix[j]);
		j++;
	}
	free(matrix);
}

char	**matrix_dup(char **old_mtx)
{
	char	**new_mtx;
	int		j;

	j = 0;
	new_mtx = (char **)malloc(sizeof(char *) * (matrix_len(old_mtx) + 1));
	while (old_mtx[j])
	{
		new_mtx[j] = ft_strdup(old_mtx[j]);
		j++;
	}
	new_mtx[j] = NULL;
	return (new_mtx);
}
