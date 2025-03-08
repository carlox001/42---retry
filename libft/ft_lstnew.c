/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:03:53 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/27 19:31:38 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* int	main(void)
{
	char	*str = "Hello Worlds";
	t_list	*node;
	char	*c;

	node = (t_list *)malloc(sizeof(t_list) * 1);
	node = ft_lstnew(str);
	c = (char *)node->content;
	printf("%p\n", node->content);
	printf("%s\n", c);
	return (0);
} */