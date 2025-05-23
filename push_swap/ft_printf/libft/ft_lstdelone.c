/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:48:27 by apeero            #+#    #+#             */
/*   Updated: 2025/02/06 17:53:17 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	del(lst->content);
}

/* void del(void *content)
{
    free(content);  // supponiamo che il contenuto sia allocato dinamicamente
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
    // Creiamo un nodo con un intero come contenuto
    int *num = malloc(sizeof(int));
    *num = 42;
    
    // Creiamo una lista con un nodo
    t_list *lst = new_node(num);
    
    // Creiamo un altro nodo da aggiungere alla lista
    int *num2 = malloc(sizeof(int));
    *num2 = 43;
    
    t_list *node2 = new_node(num2);
    lst->next = node2;
    
    // Stampa prima della rimozione
    printf("Prima: %d -> %d\n", *(int *)lst->content, *(int *)node2->content);
    
    // Rimuoviamo il primo nodo
    ft_lstdelone(lst, del);
    
    // Stampa dopo la rimozione
    printf("Dopo: %d\n", *(int *)node2->content);
    
    // Liberiamo il secondo nodo
    ft_lstdelone(node2, del);

    return 0;
}
 */