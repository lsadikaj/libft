/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:45:34 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/03 10:58:45 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;
    
    d = (unsigned char *)dst;
    s = (const unsigned char *)src;
    while (n--)
    {
        *d = *s;
        d++;
        s++;
    }
    return dst;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char    src[] = "Hello, World!";
    char    dst[20];
    
    ft_memcpy(dst, src, 13);
    dst[13] = '\0';

    printf("Copied string: %s\n", dst);
    return (0);
}