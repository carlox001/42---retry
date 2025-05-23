/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:31:37 by apeero            #+#    #+#             */
/*   Updated: 2025/02/06 17:53:56 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
t_list *ft_lstnew(void *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

void print_content(void *content) {
    printf("%d ", *(int *)content);
}

int main() {
    // Creazione dei nodi della lista
    int a = 1, b = 2, c = 3;
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);

    // Collegamento dei nodi
    node1->next = node2;
    node2->next = node3;

    // Test della funzione ft_lstiter
    printf("Contenuti della lista: ");
    ft_lstiter(node1, print_content);
    printf("\n");

    // Deallocazione della memoria (optional, per evitare perdite di memoria)
    free(node1);
    free(node2);
    free(node3);

    return 0;
} */