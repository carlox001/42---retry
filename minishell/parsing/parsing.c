/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:45:00 by sfiorini          #+#    #+#             */
/*   Updated: 2025/05/12 18:43:21 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parsing(char *str, t_program *shell)
{
	char	**mtx_tmp;
	int		k;

	if (only_spaces(str) == 1)
		return (0);
	if (check_parsing_start(shell, str) == 1)
		return (0);
	k = 0;
	parsing_core_expansion(shell, &k);
	if (shell->mtx_line[0] == NULL && k == 1)
		return (free_matrix(shell->mtx_line), 0);
	mtx_tmp = realloc_mtx_parsing(shell->mtx_line, k);
	free_matrix_len(shell->mtx_line, k);
	shell->mtx_line = matrix_dup(mtx_tmp);
	free_matrix(mtx_tmp);
	if (check_pipe(shell->mtx_line) == 1)
	{
		free_matrix(shell->mtx_line);
		ft_putstr_fd("syntax error\n", 2);
		shell->exit_code = 2;
		return (0);
	}
	print_matrix(shell->mtx_line);
	return (1);
}

void	parsing_core_expansion(t_program *shell, int *k)
{
	char	*tmp;

	while (shell->mtx_line[*k])
	{
		if (shell->mtx_line[*k][0] == '\0' && shell->mtx_line[*k + 1] != NULL)
		{
			free(shell->mtx_line[*k]);
			shell->mtx_line[*k] = ft_strdup("\"\"");
		}
		(*k)++;
	}
	*k = -1;
	while (shell->mtx_line[++*k])
	{
		if (shell->mtx_line[*k][0] == '<' && shell->mtx_line[*k][0] == '<')
			(*k) += 2;
		if (shell->mtx_line[*k] == NULL)
			break ;
		if (check_dollar(shell->mtx_line[*k]) == 1)
		{
			tmp = shell->mtx_line[*k];
			shell->mtx_line[*k] = expansion_variable2(tmp, shell);
			free(tmp);
		}
	}
}

int	check_parsing_start(t_program *shell, char *str)
{
	if (first_checks(str, shell) == 1)
		return (1);
	if (matrix_handler(str, shell) == 1)
		return (1);
	if (matrix_len(shell->mtx_line) != 0 && \
	(shell->mtx_line[matrix_len(shell->mtx_line) - 1][0] == '<' || \
		shell->mtx_line[matrix_len(shell->mtx_line) - 1][0] == '>'))
	{
		ft_putstr_fd("shell: syntax error near unexpected token \
`newline'\n", 2);
		shell->exit_code = 2;
		return (1);
	}
	if (matrix_len(shell->mtx_line) != 0 && \
	shell->mtx_line[matrix_len(shell->mtx_line) - 1][0] == '|')
	{
		ft_putstr_fd("shell: open quotes near `|'\n", 2);
		free_matrix(shell->mtx_line);
		shell->exit_code = 1;
		return (1);
	}
	return (0);
}

int	first_checks(char *str, t_program *shell)
{
	if (str[0] == '\0')
		return (1);
	if (str[ft_strlen(str) - 1] == '>' || str[ft_strlen(str) - 1] == '<')
	{
		ft_putstr_fd("shell: syntax error near unexpected token \
`newline'\n", 2);
		shell->exit_code = 2;
		return (1);
	}
	if (check_quotes(str) == 1)
	{
		ft_putstr_fd("shell: syntax error: open quotes\n", 2);
		shell->exit_code = 2;
		return (1);
	}
	if (check_operators(str, shell) == 1)
	{
		shell->exit_code = 2;
		return (1);
	}
	return (0);
}

char	**realloc_mtx_parsing(char **old_mtx, int len)
{
	char	**new_mtx;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = count_new_matrix(old_mtx, len);
	new_mtx = (char **)malloc(sizeof(char *) * (count + 1));
	if (new_mtx == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (old_mtx[i] != NULL)
		{
			new_mtx[j] = ft_strdup(old_mtx[i]);
			j++;
		}
		i++;
	}
	new_mtx[j] = NULL;
	return (new_mtx);
}
