/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:00:20 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/04 13:24:55 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *result;
    size_t  len1;
    size_t  len2;
    size_t  i;
    
    if (!s1 || !s2)
        return (NULL);
    len1 = 0;
    while (s1[len1])
        len1++;
    len2 = 0;
    while (s2[len2])
        len2++;
    result = (char *)malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    i = 0;
    while (i < len1)
    {
        result[i] = s1[i];
        i++;
    }
    while (i < len1 + len2)
    {
        result[i] = s2[i - len1];
        i++;
    }
    result[i] = '\0';
    return (result);
}

#include <stdio.h>

int main() {
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *result;

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