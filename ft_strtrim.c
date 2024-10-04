/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:26:40 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/04 13:42:55 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start = 0;
    size_t end = 0;
    size_t len = 0;
    char *result;

    if (!s1 || !set)
        return (NULL);
    
    while (s1[start] && s1[start] == *set)
        start++;
    
    while (s1[end])
        end++;
    
    while (end > start && s1[end - 1] == *set)
        end--;
    
    len = end - start;
    result = (char *)malloc(len + 1);
    if (!result)
        return (NULL);
    
    i = 0;
    while (i < len)
    {
        result[i] = s1[start + i];
        i++;
    }
    result[len] = '\0';
    return (result);
}



#include <stdio.h>

int main() {
    char *s1 = "  Hello, world!  ";
    char *set = " ";
    char *result;

    result = ft_strtrim(s1, set);
    printf("Test 1 - Expected: 'Hello, world!' | Result: '%s'\n", result);
    free(result);

    s1 = "!!!Hello!!!";
    set = "!";
    result = ft_strtrim(s1, set);
    printf("Test 2 - Expected: 'Hello' | Result: '%s'\n", result);
    free(result);

    s1 = "";
    set = " ";
    result = ft_strtrim(s1, set);
    printf("Test 3 - Expected: '' | Result: '%s'\n", result);
    free(result);

    return 0;
}