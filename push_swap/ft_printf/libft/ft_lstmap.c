/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:55:54 by apeero            #+#    #+#             */
/*   Updated: 2025/02/06 17:54:20 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

/* void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
} */

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list		*new;
	t_list		*result;

	if (!lst)
		return (NULL);
	result = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstdelone(new, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}

/* // Funzione per liberare il contenuto di un nodo
void	del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	int	*new_content = malloc(sizeof(int));
	*new_content = *(int *)content + 1; 
	return (new_content);
}

// Funzione di test
int main(void)
{
	// Creiamo una lista di esempio
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	int val1 = 1, val2 = 2, val3 = 3;

	node1->content = &val1;
	node1->next = node2;

	node2->content = &val2;
	node2->next = node3;

	node3->content = &val3;
	node3->next = NULL;

	// Applichiamo ft_lstmap alla lista
	t_list *new_list = ft_lstmap(node1, f, del);

	// Stampa i contenuti della nuova lista
	t_list *tmp = new_list;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}

	// Liberiamo la memoria
	tmp = new_list;
	while (tmp)
	{
		t_list *to_free = tmp;
		tmp = tmp->next;
		del(to_free->content);
		free(to_free);
	}

	// Liberiamo la memoria della lista originale
	free(node1);
	free(node2);
	free(node3);

	return 0;
}
 */