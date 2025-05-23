/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:54:39 by apeero            #+#    #+#             */
/*   Updated: 2025/02/06 17:52:42 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

/* 
int main()
{
    int value = 42;
    
    t_list *node = ft_lstnew(&value); 
    if (node != NULL)
    {
        printf("Nodo creato con successo!\n");
        printf("Contenuto del nodo: %d\n", *(int *)node->content); 
        printf("Il puntatore 'next' del nodo è: %p\n", node->next);
    }
    else
    {
        printf("Errore nella creazione del nodo.\n");
    }
    free(node);
    return 0;
} */