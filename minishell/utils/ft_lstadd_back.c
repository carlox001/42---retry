/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:37:58 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!new)
		return ;
	l = ft_lstlast(*lst);
	if (!l)
		*lst = new;
	else
		l->next = new;
}

// int main()
// {
// 	t_list	**pinco = (t_list **)malloc(sizeof(t_list *) * 3);
// 	t_list	*p1 = ft_lstnew("accademia delle belle arti");
// 	t_list	*p2 = ft_lstnew("studente tedesco");
// 	t_list	*p3 = ft_lstnew("abuso");
// 	ft_lstadd_back(pinco, p1);
// 	ft_lstadd_back(pinco, p2);
// 	ft_lstadd_back(pinco, p3);
// 	while (*pinco)
// 	{
// 		printf("%s\n", (char *)(*pinco)->content);
// 		*pinco = (*pinco)->next;
// 	}
// }
