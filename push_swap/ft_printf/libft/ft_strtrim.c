/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:20:48 by apeero            #+#    #+#             */
/*   Updated: 2024/11/22 16:20:50 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;

	start = 0;
	len = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	if (start == len)
	{
		return (ft_strdup(""));
	}
	while (len > 0 && ft_strchr(set, s1[len - 1]))
	{
		len--;
	}
	return (ft_substr(s1, start, len - start));
}

/* 
int main() {
    // Eseguiamo 50 test per ft_strtrim
    const char *test_strings[50] = {
        "  hello world  ",
        "   test   ",
        "abcabcabc",
        "   ",
        "abcde",
        "   abcde   ",
        "12345  ",
        "  12345",
        "hello",
        "   ",
        "abc",
        "xyz  ",
        "   123 ",
        "abcdefg",
        "  test1234 ",
        "foo  ",
        " bar",
        "  foo bar ",
        "leading whitespace",
        "trailing whitespace   ",
        "spaces in the middle",
        "##test##",
        "   ##test##  ",
        "abcdef   ",
        "   abcdef",
        "123##abc##",
        "   ##xyz##   ",
        "trim me  ",
        "   abc 123   ",
        "goodbye   ",
        "   goodbye",
        "full test case",
        "long text with multiple spaces  ",
        "empty string",
        "   trim    ",
        "startandend   ",
        "   endtest   ",
        "randomtest",
        " test case ",
        "leadingtrimtest",
        " testtrim ",
        "justspaces    ",
        "##onlyhashes##",
        "   ##another##   ",
        "no trim",
        "trimexample    ",
        "randominput1234",
        "test at end   ",
        "   spaces at start",
        "   multiple    spaces   "
    };
    
    const char *set = "y"; // Setto caratteri da rimuovere (spazi)
    
    for (int i = 0; i < 50; i++) {
        char *result = ft_strtrim((char *)test_strings[i], set);
        printf("Test %d: O: '%s'|New: '%s'\n", i + 1, test_strings[i], result);
        free(result); // Liberiamo la memoria allocata
    }

    return 0;
} */
