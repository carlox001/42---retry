/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:51:59 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s)
{
	char	*rts;
	size_t	a;

	a = 0;
	rts = (char *)s;
	rts = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rts)
		return (NULL);
	while (s[a] != '\0')
	{
		rts[a] = s[a];
		a++;
	}
	rts[a] = '\0';
	return (rts);
}

// int main() {
//     const char *str1 = "Ciao mondo!";
//     const char *str2 = "Test di duplicazione.";
//     const char *str3 = NULL;

//     char *dup1 = ft_strdup(str1);
//     if (dup1)
//         printf("Duplicato di '%s': %s\n", str1, dup1);
//     else
//         printf("Errore nella duplicazione della stringa '%s'\n", str1);

//     char *dup2 = ft_strdup(str2);
//     if (dup2)
//         printf("Duplicato di '%s': %s\n", str2, dup2);
//     else
//         printf("Errore nella duplicazione della stringa '%s'\n", str2);

//     char *dup3 = ft_strdup(str3);
//     if (dup3 == NULL)
//         printf("Duplicazione di una stringa NULL: OK (corretto)\n");
//     return 0;
// }