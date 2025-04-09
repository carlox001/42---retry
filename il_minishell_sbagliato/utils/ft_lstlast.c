/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:21:38 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int main()
// {
// 	t_list	**pinco = (t_list **)malloc(sizeof(t_list *) * 3);
// 	t_list	*p = ft_lstnew("750 cavalli");
// 	t_list	*p2 = ft_lstnew("moto");
// 	t_list	*p3 = ft_lstnew("caschi");
// 	ft_lstadd_front(pinco, p);
// 	ft_lstadd_front(pinco, p2);
// 	ft_lstadd_front(pinco, p3);
// 	printf("%s", (char *)ft_lstlast(*pinco)->content);
// 	return (0);
// }