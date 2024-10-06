/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:32:25 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/05 20:26:03 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include <stdlib.h>

char    **ft_split(char const *s, char c)
{
    char    **arr;
    size_t  i, j, k, word_len;

    if (!s || !(arr = malloc((100) * sizeof(char *))))
        return (NULL);
    i = 0;
    k = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            word_len = 0;
            while (s[i + word_len] && s[i + word_len] != c)
                word_len++;
            arr[k] = (char *)malloc((word_len + 1) * sizeof(char));
            if (!arr[k])
                return (NULL);
            j = 0;
            while (j < word_len)
                arr[k][j++] = s[i++];
            arr[k++][j] = '\0';
        }
    }
    arr[k] = NULL;
    return (arr);
}

#include <stdio.h>

int main(void)
{
    char **result;
    int i;

    // Test 1 : Simple string with spaces
    result = ft_split("Hello world this is 42", ' ');
    printf("Test 1:\n");
    i = 0;
    while (result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    // Test 2 : Multiple delimiters in a row
    result = ft_split("42___school___is___fun", '_');
    printf("Test 2:\n");
    i = 0;
    while (result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    // Test 3 : String without delimiters
    result = ft_split("JustOneWord", ' ');
    printf("Test 3:\n");
    i = 0;
    while (result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    // Test 4 : Empty string
    result = ft_split("", ' ');
    printf("Test 4:\n");
    i = 0;
    while (result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}