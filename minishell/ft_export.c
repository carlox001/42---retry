/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:52:42 by sfiorini          #+#    #+#             */
/*   Updated: 2025/04/04 12:34:03 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//problema in matrix handler quando si va a scrivere tipo : export d
// famo gli exit code


void	add_to_export_env(char *str, t_program *shell)
{
	int		i;
	char	**new_mtx;
	char	*tmp;

	i = 0;
	while (shell->export_env[i])
	{
		if (ft_strncmp(shell->export_env[i], str, ft_strlen(str)) == 0 \
			&& ft_strlen(str) == ft_strlen(shell->export_env[i]))
			return ;
		if (ft_strncmp(shell->export_env[i], str, ft_strlen(str)) == 0 \
			&& str[ft_strlen(shell->export_env[i])] == '=')
		{
			free(shell->export_env[i]);
			shell->export_env[i] = ft_strdup(str); 
			return ;
		}
		i++;
	}
	new_mtx = (char **)malloc(sizeof(char *) * \
		(matrix_len(shell->export_env) + 2));
	if (new_mtx == NULL)
		return ;
	i = 0;
	while (shell->export_env[i])
	{
		new_mtx[i] = ft_strdup(shell->export_env[i]);
		i++;
	}
	tmp = ft_strdup(str);
	new_mtx[i] = ft_strjoin(tmp, "\n");
	free(tmp);
	new_mtx[i + 1] = NULL;
	free_matrix(shell->export_env);
	shell->export_env = matrix_dup(new_mtx);
	free_matrix(new_mtx);
}

void	ft_export(t_program *shell)
{
	char	*dup;
	int		i;
	int		flag;

	if (only_export(shell) == 1)
		return ;
	i = 0;
	if (export_parsing(shell) == 1)
		return ;
	dup = ft_strdup(shell->mtx_line[shell->i + 1]);
	printf("dup: %s\n", dup);
	shell->export_arg = remove_all_quotes(dup);
	free(dup);
	flag =  0;
	while (shell->export_arg[i] && flag == 0)
	{
		if (shell->export_arg[i] == '=')
			flag = 1;
		if (shell->export_arg[i] == '>' || shell->export_arg[i] == '<')
			break ;
		i++;
	}
	if (flag == 0)
	{
		//sub
		add_to_export_env(shell->export_arg, shell);
		return (free(shell->export_arg));
	}
	export_core(shell, i, shell->env, 0);
	// export_core(shell, i, shell->export_env, 1);
	free(shell->export_arg);
}

void	export_core(t_program *shell, int i, char **env, int flag)
{
	char	*err;
	int		value;

	shell->flag = 0;
	value = is_there_in_env(shell, i, env, &shell->flag);
	printf("calee: %d\n", value);
	if (value == -2)
	{
		err = ft_substr(shell->export_arg, 0, i);
		printf("shell: export: `%s': not a valid identifier\n", err);
		shell->exit_code = 1;
		free(err);
	}
	if (value >= 0)
		change_export_value(shell, i, value, env);
	else
	{
		if (realloc_env(shell, env, flag) == 1)
			return ;
	}
	printf("ho aggiunto\n");
}

// cambia il valore inserito all'interno 
// di env senza la riallocazione
void	change_export_value(t_program *shell, int i, int value, char **env)
{
	char	*dup2;
	char	*dup;

	if (shell->flag == 1)
	{
		dup = ft_strdup(env[value]);
		free(env[value]);
		dup2 = ft_substr(shell->export_arg, i, ft_strlen(shell->export_arg));
		env[value] = ft_strjoin(dup, dup2);
		free(dup);
		free(dup2);
	}
	else
	{
		free(env[value]);
		env[value] = ft_strdup(shell->export_arg);
	}
}

// rialloca env poiche' la nuova stringa non esiste
int	realloc_env(t_program *shell, char **env, int flag)
{
	char	**mtx_dup;
	int		i;

	mtx_dup = matrix_dup(env);
	if (mtx_dup == NULL)
		return (1);
	// free_matrix(env);
	env = (char **)malloc(sizeof(char *) * (matrix_len(mtx_dup) + 2));
	if (env == NULL)
		return (1);
	i = 0;
	while (mtx_dup[i])
	{
		env[i] = ft_strdup(mtx_dup[i]);
		i++;
	}
	env[i] = shell->export_arg;
	env[i + 1] = NULL;
	free_matrix(mtx_dup);
	if (flag == 0)
		free_matrix(shell->env);
	else
		free_matrix(shell->export_env);
	return (0);
}


// esegue del parsing aggiuntivo peril comando export
int	export_parsing(t_program *shell)
{
	int		i;
	char	*str;

	
	// printf("shell->mtx_line[shell->i + 1]: %s\n", shell->mtx_line[shell->i + 1]);
	str = ft_strdup(shell->mtx_line[shell->i + 1]);
	i = 0;
	while (str[i] != '=' && str[i])
	{
		if (str[i] == '+' && str[i + 1] == '=')
			break ;
		if (ft_isalnum(str[i]) != 1  && str[i] != '_' && \
			str[i] != '\'' && str[i] != '"')
		{
			printf("shell: export: `%s': not a valid identifier\n", str);
			shell->exit_code = 1;
			free(str);
			return (1);
		}
		i++;
	}
	if (export_parsing_quote(str) == 1)
	{
		printf("shell: export: `%s': not a valid identifier\n", str);
		shell->exit_code = 1;
		free(str);
		return (1);
	}
	// if (i == ((int)ft_strlen(str) + 1)) //nn ho cpt
	// 	printf("culo\n");
	free(str);
	return (0);

}

int	export_parsing_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '"')
		{

			while (str[i] && (str[i] != '=' || str[i] != '"'))
			{
				if (str[i] == '\'')
					return (1);
				i++;
			}
		}
		else if (str[i] == '\'')
		{
			while (str[i] && (str[i] != '=' || str[i] != '\''))
			{
				if (str[i] == '"')
					return (1);
				i++;
			}
		}
		else
			i++;
	}
	return (0);
}

int	only_export(t_program *shell)
{
	int	i;
	int	j;

	i = 0;
	if (shell->mtx_line[shell->i + 1] == NULL)
	{
		while (shell->export_env[i])
		{
			printf("declare -x ");
			j = 0;
			while (shell->export_env[i][j])
			{
				while (shell->export_env[i][j] && shell->export_env[i][j] != '=')
				{
					printf("%c", shell->export_env[i][j]);
					j++;
				}
				if (shell->export_env[i][j] == '=')
				{
					j++;
					printf("=\"");
					while (shell->export_env[i][j])
					{
						printf("%c", shell->export_env[i][j]);
						j++;
					}
					printf("\"\n");
				}
			}
			i++;
		}
		return (1);
	}
	return (0);
}

