/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:40:26 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/07 10:51:30 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		del(node->content);
		free(node);
	}
}

/* static void	del(void *content)
{
	ft_calloc(ft_strlen((char *)content), sizeof(content));
}

int	main(void)
{
	t_list	*node;
	t_list	*node1;
	t_list	**lst;
	char	*s;
	char	*l;

	node = (t_list *)malloc(sizeof(t_list) * 1);
	node1 = (t_list *)malloc(sizeof(t_list) * 1);
	lst = (t_list **)malloc(sizeof(t_list *) * 2);
	s = (char *)malloc(sizeof(char) * 3);
	l = (char *)malloc(sizeof(char) * 4);
	s[0] = 'c';
	s[1] = 'u';
	s[2] = '\0';
	l[0] = 't';
	l[1] = 't';
	l[2] = 'o';
	l[3] = '\0';
	node = ft_lstnew(s);
	node1 = ft_lstnew(l);
	ft_lstadd_front(lst, node1);
	ft_lstadd_front(lst, node);
	printf("%p : %s\n", node->content, (char *)node->content);
	printf("%p : %s\n", node1->content, (char *)node1->content);
	ft_lstclear(lst, &del);
	printf("%p : %s\n", node->content, (char *)node->content);
	printf("%p : %s\n", node1->content, (char *)node1->content);
	return (0);
} */