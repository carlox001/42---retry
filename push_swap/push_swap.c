/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:56:46 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 13:07:28 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//controllo sui doppi con 0 (es 4 e 04)

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
	start_and_finish(head, argc);
	return (0);
}
