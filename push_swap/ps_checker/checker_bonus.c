/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:26:19 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 13:07:36 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	operations(char *command, t_head *head)
{
	if (ft_strncmp(command, "pa", ft_strlen(command) - 1) == 0)
		ft_pa(head);
	else if (ft_strncmp(command, "pb", ft_strlen(command) - 1) == 0)
		ft_pb(head);
	else if (ft_strncmp(command, "sa", ft_strlen(command) - 1) == 0)
		ft_sa(&(*head).head_a);
	else if (ft_strncmp(command, "sb", ft_strlen(command) - 1) == 0)
		ft_sb(&(*head).head_b);
	else if (ft_strncmp(command, "ss", ft_strlen(command) - 1) == 0)
		ft_ss(head);
	else if (ft_strncmp(command, "ra", ft_strlen(command) - 1) == 0)
		ft_ra(&(*head).head_a);
	else if (ft_strncmp(command, "rb", ft_strlen(command) - 1) == 0)
		ft_rb(&(*head).head_b);
	else if (ft_strncmp(command, "rr", ft_strlen(command) - 1) == 0)
		ft_rr(head);
	else if (ft_strncmp(command, "rra", ft_strlen(command) - 1) == 0)
		ft_rra(&(*head).head_a);
	else if (ft_strncmp(command, "rrb", ft_strlen(command) - 1) == 0)
		ft_rrb(&(*head).head_b);
	else if (ft_strncmp(command, "rrr", ft_strlen(command) - 1) == 0)
		ft_rrr(head);
}

void	read_move(t_head *head)
{
	char	*bff;

	while (1)
	{
		bff = get_next_line(0);
		if (!bff)
			break ;
		operations(bff, head);
		free(bff);
	}
}

int	main(int argc, char **argv)
{
	t_head	*head;
	int		i;

	i = 1;
	head = (t_head *)malloc(sizeof(t_head));
	if (!head)
	{
		free_all(head);
		return (1);
	}
	head->head_a = NULL;
	head->head_b = NULL;
	if (argc == 1 || !check_char(argv) || !check_double(argv)
		|| !check_int(argv))
	{
		free_all(head);
		return (0);
	}
	while (i < argc)
	{
		fillstack(&head->head_a, ft_atoi(argv[i]));
		i++;
	}
	start_finish(head);
	free(head);
}
