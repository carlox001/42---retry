/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:25:47 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main()
// {
// 	int i = 0;
// 	t_list	**lst = (t_list**)malloc(sizeof(t_list *) * 3);
// 	t_list	*p = ft_lstnew("sbusto");
// 	t_list	*p2 = ft_lstnew("perforzingher");
// 	t_list	*p3 = ft_lstnew("Mario Sturniolo");
// 	ft_lstadd_front(lst, p3);
// 	ft_lstadd_front(lst, p2);
// 	ft_lstadd_front(lst, p);
// 	while ((*lst)->next)
// 	{
// 		printf("%d:  %s\n", i, (char *)(*lst)->content);
// 		*lst = (*lst)->next;
// 		i++;
// 	}
// 	printf("%d: %s\n", i, (char *)(*lst)->content);
// }