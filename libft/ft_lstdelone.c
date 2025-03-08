/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:24:10 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/01 10:37:00 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/* static void	del(void *content)
{
	ft_calloc(ft_strlen((char *)content), sizeof(content));
}

int	main(void)
{
	t_list	*node;

	node = ft_lstnew("ciao");
	if (node == NULL)
		return (1);
	printf("%p : %s\n", node->content, (char *)node->content);
	ft_lstdelone(node, *del);
	printf("%p : %s\n", node->content, (char *)node->content);
	return (0);
} */