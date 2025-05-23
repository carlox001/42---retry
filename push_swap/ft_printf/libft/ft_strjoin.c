/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:58:17 by apeero            #+#    #+#             */
/*   Updated: 2024/11/22 15:58:19 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*joinstr;

	i = 0;
	if (s1 == NULL)
		return ((char *)s2);
	else if (s2 == NULL)
		return ((char *)s1);
	joinstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (joinstr == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		joinstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		joinstr[i] = *s2;
		s2++;
		i++;
	}
	joinstr[i] = '\0';
	return (joinstr);
}

/* 
int main()
{
    // 50 test cases
    char *test_cases[53][2] = {
        {"Hello", "World"},
        {"", "World"},
        {"Hello", ""},
        {"", ""},
        {NULL, "World"},
        {"Hello", NULL},
        {NULL, NULL},
        {"12345", "67890"},
        {"Test", "1234"},
        {"Open", "AI"},
        {"Concat", "enation"},
        {"Empty", ""},
        {"This", "is"},
        {"only", "testing"},
        {"Super", "califragilisticexpialidocious"},
        {"Small", "test"},
        {"Large", "stringtest"},
        {"First", "Second"},
        {"Foo", "Bar"},
        {"One", "More"},
        {"Stack", "Overflow"},
        {"The", "QuickBrownFox"},
        {"Jump", "edOver"},
        {"Lazy", "Dog"},
        {"X", "Y"},
        {"Left", "Right"},
        {"Day", "Night"},
        {"Computer", "Science"},
        {"Apple", "Pie"},
        {"Banana", "Split"},
        {"Orange", "Juice"},
        {"Python", "C"},
        {"Java", "Script"},
        {"Star", "Wars"},
        {"Electric", "Car"},
        {"Home", "Work"},
        {"Life", "Cycle"},
        {"Black", "White"},
        {"Red", "Blue"},
        {"Fast", "Slow"},
        {"Up", "Down"},
        {"Winter", "Summer"},
        {"Spring", "Autumn"},
        {"Music", "Harmony"},
        {"Book", "Shelf"},
        {"Art", "Gallery"},
        {"Window", "Door"},
        {"Mountain", "Climb"},
        {"Ocean", "Wave"},
        {"Computer", "Program"},
        {"Travel", "Adventure"},
        {"Sun", "Moon"},
        {"Cloud", "Sky"}
    };

    for (int i = 0; i < 53; i++)
    {
        printf("Test case %d:\n", i + 1);
        printf("%s",ft_strjoin(test_cases[i][0], test_cases[i][1]));
        printf("\n");
    }

    return 0;
} */