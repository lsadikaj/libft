/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:06:54 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/03 09:41:09 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    bzero(void *s, size_t n)
{
    size_t  i;
    unsigned char    *ptr;
    
    ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}

#include <stdio.h>

int main()
{
    char    str[50] = "Hello, world!";
    printf("Before ft_bzero: %s\n", str);

    ft_bzero(str + 6, 5);
    printf("After ft_bzero: %s\n", str);

    return (0);
}