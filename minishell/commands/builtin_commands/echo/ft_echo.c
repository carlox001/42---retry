/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:28 by cazerini          #+#    #+#             */
/*   Updated: 2025/04/24 16:18:56 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"


// sistematre piu' quotes all'inizio
// controllare che ci siano solo ed esculivamente caratteri prima dell'uguale _ va bene
// facciamo echo per echo $?

//gestire parsing meglio imbecilli (es: ''ciao'')
// export non prende se ci sono solo numeri prima dell'uguale

void	ft_echo(t_program *shell)
{
	char	*str;
	char	*str2;
	int		i;
	int		len;

	if (shell->mtx_line[shell->i + 1] == NULL)
	{
		printf("\n");
		return ;
	}
	shell->nflag = check_nflag(shell->mtx_line[shell->i + 1], shell);
	len = count_args(shell->mtx_line, shell->i + 1);
	i = 0;
	while (i < len)
	{
		str = ft_strdup(shell->mtx_line[shell->i + 1]);
		str2 = remove_external_quotes(str, '"');
		str2 = remove_external_quotes(str, '\'');
		if (str2 == NULL)
			str2 = ft_strdup(str);
		free(str);
		ft_echo_core(shell, str2, &i, len);
	}
	if (shell->nflag != 1)
		printf("\n");
}


void	ft_echo_core(t_program *shell, char *str2, int *i, int len)
{
	
	if (str2[0] != '>')
	{
		if (str2)
		{
			if (*i != len)
			{
				if (str2[0] == '$' && str2[1] == '?')
				{
					printf("%d ", shell->exit_code);
					shell->i++;
				}
				else
					printf("%s ", str2);
			}
			else
			{
				if (str2[0] == '$' && str2[1] == '?')
				{
					printf("%d", shell->exit_code);
					shell->i++;
				}
				else
					printf("%s", str2);
			}
		}
	}
	else
	{
		(*i)++;
		shell->i++;
		if (shell->mtx_line[shell->i + 1] != NULL)
		{
			(*i)++;
			shell->i++;
		}
	}
	free(str2);
	(*i)++;
	shell->i++;
	shell->exit_code = 0;
}
