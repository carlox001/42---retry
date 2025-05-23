/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:01:27 by apeero            #+#    #+#             */
/*   Updated: 2025/02/06 17:53:40 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
 */
void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*ptr;

	ptr = *lst;
	while (*lst)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		del(ptr->content);
	}
}

/* void del(void *content)
{
    free(content);  // Supponiamo che il contenuto sia allocato dinamicamente
}

t_list *new_node(void *content)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

int main()
{
    // Creiamo alcuni nodi con contenuti dinamici
    int *num1 = malloc(sizeof(int));
    *num1 = 42;
    int *num2 = malloc(sizeof(int));
    *num2 = 43;
    
    // Creiamo la lista concatenata
    t_list *lst = new_node(num1);
    t_list *node2 = new_node(num2);
    lst->next = node2;
    
    // Stampa la lista prima di chiamare ft_lstclear
    printf("Contenuti lista prima della rimozione:\n");
    t_list *ptr = lst;
    while (ptr)
    {
        printf("%d -> ", *(int *)ptr->content);
        ptr = ptr->next;
    }
    printf("NULL\n");
    
    // Chiamiamo ft_lstclear per eliminare tutta la lista
    ft_lstclear(&lst, del);
    
    // Verifica che la lista è stata effettivamente svuotata
    if (lst == NULL)
        printf("La lista è stata svuotata con successo!\n");
    else
        printf("La lista non è vuota!\n");
    
    return 0;
} */