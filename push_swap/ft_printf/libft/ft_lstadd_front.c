/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:32 by apeero            #+#    #+#             */
/*   Updated: 2024/11/25 14:16:33 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* void print_list(t_list *lst)
{
    while (lst != NULL)
    {
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main()
{
    // Creazione di un nodo con contenuto 42
    int a = 42;
    t_list *node1 = malloc(sizeof(t_list));
    node1->content = &a;
    node1->next = NULL;

    // Creazione di un nodo con contenuto 100
    int b = 100;
    t_list *node2 = malloc(sizeof(t_list));
    node2->content = &b;
    node2->next = NULL;

    t_list *head = node1;
    ft_lstadd_front(&head, node2);

    // Stampa della lista
    print_list(head); 

    // Liberare la memoria
    free(node1);
    free(node2);

    return 0;
} */