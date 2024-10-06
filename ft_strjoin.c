/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:00:20 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/04 17:05:15 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include <stdlib.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  i = 0, j = 0, len_s1 = 0, len_s2 = 0;
    char    *result;

    if (!s1 || !s2)
        return (NULL);
    while (s1[len_s1])
        len_s1++;
    while (s2[len_s2])
        len_s2++;
    result = (char *)malloc(len_s1 + len_s2 + 1);
    if (!result)
        return (NULL);
    while (i < len_s1)
    {
        result[i] = s1[i];
        i++;
    }
    while (j < len_s2)
        result[i++] = s2[j++];
    result[i] = '\0';
    return (result);
}


#include <stdio.h>

int main() {
    char *s1 = "Hello, ";
    char *s2 = "world!";

    result = ft_strjoin(s1, s2);
    printf("Test 1 - Expected: 'Hello, world!' | Result: '%s'\n", result);
    free(result);

    result = ft_strjoin(s1, "");
    printf("Test 2 - Expected: 'Hello, ' | Result: '%s'\n", result);
    free(result);

    result = ft_strjoin("", s2);
    printf("Test 3 - Expected: 'world!' | Result: '%s'\n", result);
    free(result);

    result = ft_strjoin("", "");
    printf("Test 4 - Expected: '' | Result: '%s'\n", result);
    free(result);

    result = ft_strjoin(s1, NULL);
    printf("Test 5 - Expected: NULL | Result: '%s'\n", result);

    result = ft_strjoin(NULL, s2);
    printf("Test 6 - Expected: NULL | Result: '%s'\n", result);

    return 0;
}