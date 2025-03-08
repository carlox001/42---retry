/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:49:41 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/03 19:46:02 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int	main(void)
{
	t_list	*node;
	t_list	*node1;

	node = ft_lstnew("ciao");
	node1 = ft_lstnew("mondo");
	ft_lstadd_front(&node1, node);
	printf("%p : %s\n", node->content, (char *)node->content);
	printf("%p : %s\n", node1->content, (char *)node1->content);
	return (0);
} */