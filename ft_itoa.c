/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:28:20 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/06 12:47:56 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include <stdlib.h>

char    *ft_itoa(int n)
{
    char    *str;
    long    nb;
    int     len;
    int     negative;

    nb = (n < 0) ? -(long)n : n;
    negative = (n < 0);
    len = (n <= 0);
    while (n && ++len)
        n /= 10;
    str = (char *)malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    while (len--)
    {
        str[len] = (nb % 10) + '0';
        nb /= 10;
    }
    if (negative)
        str[0] = '-';
    return (str);
}

#include <stdio.h>

int main(void)
{
    printf("Test 1: %s\n", ft_itoa(123));         // Devrait afficher "123"
    printf("Test 2: %s\n", ft_itoa(-456));        // Devrait afficher "-456"
    printf("Test 3: %s\n", ft_itoa(0));           // Devrait afficher "0"
    printf("Test 4: %s\n", ft_itoa(-2147483648)); // Devrait afficher "-2147483648"
    printf("Test 5: %s\n", ft_itoa(2147483647));  // Devrait afficher "2147483647"

    return 0;
}