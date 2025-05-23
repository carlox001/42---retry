/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:33:08 by apeero            #+#    #+#             */
/*   Updated: 2024/11/25 14:33:09 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

int	ft_lstsize(t_list *lst)
{
	int		cont;

	cont = 0;
	while (lst)
	{
		lst = lst->next;
		cont++;
	}
	return (cont);
}

/* // Funzione per aggiungere un nodo alla testa della lista
void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst && new)
    {
        new->next = *lst;
        *lst = new;
    }
}

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

int main()
{
    // Creiamo alcuni nodi di esempio
    int a = 42, b = 100, c = 56, d = 78;

    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);
	t_list *node4 = ft_lstnew(&d);

    // Creiamo una lista vuota
    t_list *head = NULL;

    ft_lstadd_front(&head, node1);  // La lista ora contiene 42
    ft_lstadd_front(&head, node2);  // La lista ora contiene 100 -> 42
    ft_lstadd_front(&head, node3);  // La lista ora contiene 56 -> 100 -> 42
    ft_lstadd_front(&head, node4);  // La lista ora contiene 56 -> 100 -> 42

    // Testiamo la funzione ft_lstsize
    int size = ft_lstsize(head);
    printf("La dimensione della lista è: %d\n", size);

    // Liberiamo la memoria
    free(node1);
    free(node2);
    free(node3);
	free(node4);
    return 0;
} */