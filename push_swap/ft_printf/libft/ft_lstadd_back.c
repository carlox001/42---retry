/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:49:07 by apeero            #+#    #+#             */
/*   Updated: 2025/02/18 14:13:29 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (ptr->next != (*lst))
		{
			ptr = ptr->next;
		}
		ptr->next = new;
	}
}
/* 
// Funzione per creare un nuovo nodo
t_list *ft_lstnew(void *content)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Funzione per stampare i valori dei nodi della lista
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main()
{
    // Creiamo alcuni nodi di esempio
    int a = 42, b = 100, c = 56;

    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);

    // Creiamo una lista vuota
    t_list *head = NULL;

    // Aggiungiamo i nodi alla fine della lista
    ft_lstadd_back(&head, node1);  // La lista ora contiene 42
    ft_lstadd_back(&head, node2);  // La lista ora contiene 42 -> 100
    ft_lstadd_back(&head, node3);  // La lista ora contiene 42 -> 100 -> 56

    // Stampa della lista
    print_list(head);  // Dovrebbe stampare: 42 -> 100 -> 56 -> NULL

    // Liberiamo la memoria
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
 */