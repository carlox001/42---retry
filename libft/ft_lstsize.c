/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:36:13 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/03 19:50:11 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		size;

	ptr = lst;
	size = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
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
	printf("%d\n", ft_lstsize(node));
	
	return (0);
} */