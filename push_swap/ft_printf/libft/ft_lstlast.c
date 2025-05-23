/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:39:58 by apeero            #+#    #+#             */
/*   Updated: 2024/11/25 14:39:59 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/* // Funzione per creare un nuovo nodo
t_list *ft_lstnew(void *content)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Funzione per aggiungere un nodo alla fine della lista
void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;
    if (*lst == NULL) 
    {
        *lst = new;
        return;
    }
    last = ft_lstlast(*lst);  // Trova l'ultimo nodo
    last->next = new;         // Aggiungi il nuovo nodo alla fine della lista
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

    // Aggiungiamo i nodi alla lista
    ft_lstadd_back(&head, node1);  // La lista ora contiene 42
    ft_lstadd_back(&head, node2);  // La lista ora contiene 42 -> 100
    ft_lstadd_back(&head, node3);  // La lista ora contiene 42 -> 100 -> 56

    // Testiamo la funzione ft_lstlast
    t_list *last_node = ft_lstlast(head);
    if (last_node != NULL)
    {
		printf("L'ultimo e' %d\n", *(int *)last_node->content);
    }
    else
    {
        printf("La lista è vuota.\n");
    }

    // Stampa della lista
    print_list(head);

    // Liberiamo la memoria
    free(node1);
    free(node2);
    free(node3);

    return 0;
} */