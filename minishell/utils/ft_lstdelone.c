/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:42:34 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void del(void *content) 
// {
//     if (content)
//         printf("Content deleted: %s\n", (char *)content);
// }

// int main() 
// {
//     char *str = "Hello, world!";
//     t_list *node = ft_lstnew(str);
//     if (node) 
// 	{
//         printf("Before deletion: %s\n", (char *)node->content);
//         ft_lstdelone(node, del);
//         printf("Node deleted.\n");
//     } 
// 	else 
//         printf("Failed to create node.\n");
//     return 0;
// }