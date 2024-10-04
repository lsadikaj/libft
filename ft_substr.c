/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:24:38 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/04 13:00:02 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t  i;
    size_t  s_len;

    if (!s)
        return (NULL);    
    s_len = 0;
    while (s[s_len])
        s_len++;
    if (start >= s_len)
    {
        substr = (char *)malloc(1);
        if (substr)
            substr[0] = '\0';
        return (substr);
    }
    if (len > s_len - start)
        len = s_len - start;
    substr = (char *)malloc(len + 1);
    if (!substr)
        return (NULL);
    i = 0;
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}

#include <stdio.h>

int main() {
    char *s = "Hello, world!";
    char *result;

    // Test 1: Extraction de la sous-chaîne de l'index 7 avec une longueur de 5
    result = ft_substr(s, 7, 5);
    printf("Test 1 - Expected: 'world' | Result: '%s'\n", result);
    free(result); // Libérer la mémoire allouée

    // Test 2: Extraction à partir d'un index supérieur à la longueur de la chaîne
    result = ft_substr(s, 20, 5);
    printf("Test 2 - Expected: '' | Result: '%s'\n", result);
    free(result); // Libérer la mémoire allouée

    // Test 3: Extraction de la sous-chaîne de l'index 0 avec une longueur de 5
    result = ft_substr(s, 0, 5);
    printf("Test 3 - Expected: 'Hello' | Result: '%s'\n", result);
    free(result); // Libérer la mémoire allouée

    // Test 4: Extraction avec une longueur plus grande que la chaîne disponible
    result = ft_substr(s, 5, 100);
    printf("Test 4 - Expected: ', world!' | Result: '%s'\n", result);
    free(result); // Libérer la mémoire allouée

    // Test 5: Extraction d'une sous-chaîne de longueur nulle
    result = ft_substr(s, 0, 0);
    printf("Test 5 - Expected: '' | Result: '%s'\n", result);
    free(result); // Libérer la mémoire allouée

    return 0;
}