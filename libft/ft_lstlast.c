/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:52:54 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/01 13:30:18 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

/* int	main(void)
{
	t_list	*node;
	t_list	*node1;
	t_list	*node2;

	node = ft_lstnew("ciao");
	node1 = ft_lstnew("mondo");
	node2 = ft_lstnew("cutto");
	ft_lstadd_front(&node2, node1);
	ft_lstadd_front(&node1, node);
	printf("%p : %s\n", node->content, (char *)node->content);
	printf("%p : %s\n", node1->content, (char *)node1->content);
	printf("%p : %s\n", node2->content, (char *)node2->content);
	printf("node: %p\n", node->next);
	printf("%p\n", ft_lstlast(node));
	return (0);
} */