/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:45:00 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/26 17:09:44 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// invalid read con es ("ls")

int	parsing(char *str, t_program *shell)
{
	char **mtx_tmp;
	int	k;
	char *tmp;
	int	check;

	// aggiungere gli exit code
	if (str[0] == '\0')
		return (0);
	if (str[ft_strlen(str) - 1] == '>' || str[ft_strlen(str) - 1] == '<')
	{
		printf("shell: syntax error near unexpected token `newline'\n");
		shell->exit_code = 2;
		return (0);
	}
	if (check_quotes(str) == 1)
	{
		printf("shell: syntax error: open quotes\n");
		shell->exit_code = 0;
		return (0);
	}
	if (check_operators(str, shell) == 1)
	{
		// printf("shell: syntax error: operators error\n");
		shell->exit_code = 0;
		return (0);
	}
	check = matrix_handler(str, shell);
	if (check > 0)
	{
		if (check == 1)
		{
			printf("Error\nfailed allocation\n");
			shell->exit_code = 0;
		}
		return (0);
	}
	if (matrix_len(shell->mtx_line) != 0 && (shell->mtx_line[matrix_len(shell->mtx_line) - 1][0] == '<' || \
		shell->mtx_line[matrix_len(shell->mtx_line) - 1][0] == '>'))
	{
		// print_matrix(shell->mtx_line);
		printf("shell: syntax error near unexpected token `newline'\n");
		shell->exit_code = 2;
		return (0);
	}
	if (matrix_len(shell->mtx_line) != 0 && shell->mtx_line[matrix_len(shell->mtx_line) - 1][0] == '|')
	{
		printf("shell: open quotes near `|'\n");
		free_matrix(shell->mtx_line);
		shell->exit_code = 1;
		return (0);
	}
	// printf("pre espansione\n");
	// print_matrix(shell->mtx_line);

	k = 0;
	while (shell->mtx_line[k])
	{
		if (shell->mtx_line[k][0] == '\0' && shell->mtx_line[k + 1] != NULL)
		{
			free(shell->mtx_line[k]);
			shell->mtx_line[k] = ft_strdup("\"\"");
		}
		k++;
	}
	k = 0;
	while (shell->mtx_line[k])
	{
		if (check_dollar(shell->mtx_line[k]) == 1)
		{
			tmp = shell->mtx_line[k];
			shell->mtx_line[k] = expansion_variable2(tmp);
			free(tmp);
		}
		k++;
	}
	if (shell->mtx_line[0] == NULL && k == 1)
	{
		free_matrix(shell->mtx_line);
		return (0);
	}

	mtx_tmp = realloc_mtx_parsing(shell->mtx_line, k);
	free_matrix_len(shell->mtx_line, k);
	shell->mtx_line = matrix_dup(mtx_tmp);
	free_matrix(mtx_tmp);
	// printf("post espansione\n");
	// print_matrix(shell->mtx_line);
	return (1);
}

char	**realloc_mtx_parsing(char **old_mtx, int len)
{
	char	**new_mtx;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (old_mtx != NULL)
			count++;
		i++;
	}
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

int	only_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '$')
			return (0);
		i++;
	}
	return (1);
}

//se null riaalloca shiftando i null
char	*expansion_variable2(char *old_str)
{
	char	*new_str;
	char	*sub_str;
	char	*tmp;
	char	*path; 
	char	*chr;
	int		i;
	int		len;

	i = 0;
	new_str = NULL;
	if (only_dollar(old_str) == 1)
		return (ft_strdup(old_str));
	while (old_str[i])
	{
		if (old_str[i] == '$' && old_str[i + 1] != '\0')
		{
			while (old_str[i] && old_str[i] == '$')
				i++;
			if (((old_str[i] == '\"' && old_str[i + 1] == '\"' ) || \
				(old_str[i] == '\'' && old_str[i + 1] == '\'' )) && \
				ft_strlen(old_str) == 3)
					return (ft_strdup("\" \""));
			if (old_str[i] == '\0')
				new_str = ft_strdup("\"\"");
			if (old_str[i] == '?')
			{
				new_str = ft_strdup("$?");
				return (new_str);
			}
			len = 0;
			while (old_str[i + len] && old_str[i + len] != '\"' && old_str[i + len] != '\'' && old_str[i + len] != '$' && old_str[i + len] != '\\')
				len++;
			sub_str = ft_substr(old_str, i, len);
			path = getenv(sub_str);
			if (path != NULL)
			{
				if (new_str == NULL)
					new_str = ft_strdup(path);
				else
				{
					tmp = new_str;
					new_str = ft_strjoin(new_str, path);
					free(tmp);
				}
			}
			free(sub_str);
			if (len == 0 && old_str[i + len] != '\"' && old_str[i + len] != '\'')
				i--;
			else
				i += len;
		}
		else
		{
			chr = malloc(sizeof(char) * 2);
			chr[0] = old_str[i];
			chr[1] = '\0';
			if (new_str == NULL)
				new_str = ft_strdup(chr);
			else
			{
				tmp = new_str;
				new_str = ft_strjoin(new_str, chr);
				free(tmp);
			}
			free(chr);
		}
		if (old_str[i] != '\0' && old_str[i] != '$')
			i++;
	}
	return (new_str);
}

int	print_parsing_errors(int flag, t_program *shell)
{
	if (flag == 1)
		printf("shell: parse error near `|'\n");
	if (flag == 2)
		printf("shell: parse error near `>'\n");
	if (flag == 3)
		printf("shell: parse error near `<'\n");
	if (flag == 4)
		printf("shell: parse error near `\\n'\n");
	if (flag == 5)
		printf("shell: parse error near `||'\n");
	if (flag == 6)
		printf("shell: syntax error\n");
	shell->exit_code = 1;
	return (1);
}
