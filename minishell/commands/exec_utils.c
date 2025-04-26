/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:13:11 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/23 19:24:56 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	***alloc_mtx(int num_commands, t_program *shell)
{
	char	***mtx_hub;
	// char	**dup_mtx;
	// int		i;
	// int		j;
	// int		k;

	// initialize_files_in(&i, &j, &k, 1);
	mtx_hub = (char ***)ft_calloc(sizeof(char **), (num_commands + 1));
	if (mtx_hub == NULL)
		return (NULL);
	// while (shell->mtx_line[i])
	// {
	// 	if (k == 0)
	// 	{
	// 		dup_mtx = (char **)ft_calloc(sizeof(char *), (matrix_len(shell->mtx_line) + 1));
	// 		if (dup_mtx == NULL)
	// 			return (NULL);
	// 	}
	// 	if (shell->mtx_line[i][0] == '|')
	// 	{
	// 		mtx_hub[j] = matrix_dup(dup_mtx);
	// 		j++;
	// 		i++;
	// 		free_matrix(dup_mtx);
	// 		k = 0;
	// 	}
	// 	else
	// 	{
	// 		dup_mtx[k] = ft_strdup(shell->mtx_line[i]);
	// 		k++; 
	// 		i++;
	// 	}
	// }
	// if (dup_mtx[0] != NULL || dup_mtx[0][0] != '\0')
	// {
	// 	mtx_hub[j] = matrix_dup(dup_mtx);
	// 	j++;
	// }
	// free_matrix(dup_mtx);
	alloc_mtx_core(shell, mtx_hub);
	return (mtx_hub);
}


void	alloc_mtx_core(t_program *shell, char ***mtx_hub)
{
	int		i;
	int		j;
	int		k;
	char	**dup_mtx;

	initialize_files_in(&i, &j, &k, 1);
	while (shell->mtx_line[i])
	{
		if (k == 0)
		{
			dup_mtx = (char **)ft_calloc(sizeof(char *), (matrix_len(shell->mtx_line) + 1));
			if (dup_mtx == NULL)
				return ;
		}
		if (shell->mtx_line[i][0] == '|')
		{
			mtx_hub[j] = matrix_dup(dup_mtx);
			j++;
			i++;
			free_matrix(dup_mtx);
			k = 0;
		}
		else
		{
			dup_mtx[k] = ft_strdup(shell->mtx_line[i]);
			k++; 
			i++;
		}
	}
	if (dup_mtx[0] != NULL || dup_mtx[0][0] != '\0')
	{
		mtx_hub[j] = matrix_dup(dup_mtx);
		j++;
	}
	free_matrix(dup_mtx);
	mtx_hub[j] = NULL;
}


void	free_matrix_pointer(char ***mtx_hub)
{
	int	i;

	i = 0;
	while (mtx_hub[i])
	{
		free_matrix(mtx_hub[i]);
		i++;
	}
	free(mtx_hub);
}
