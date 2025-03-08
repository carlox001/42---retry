/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:08:58 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/03 19:53:04 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
}

/* int	main(void)
{
	t_list	*node;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node = ft_lstnew("ciao");
	node1 = ft_lstnew("mondo");
	node2 = ft_lstnew("cutto");
	node3 = ft_lstnew("cu");
	ft_lstadd_front(&node2, node1);
	ft_lstadd_front(&node1, node);
	ft_lstadd_back(&node, node3);
	printf("%p\n", node2->next);
	printf("%p\n", node3);
	return (0);
} */