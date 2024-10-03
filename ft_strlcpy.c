/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:59:28 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/03 14:11:21 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t  strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  i;
    size_t  j;
    
    i = 0;
    while (src[i] != '\0')
        i++;
    if (dstsize > 0)
    {
        j = 0;
        while (j < dstsize - 1 && src[j] != '\0')
        {
            dst[j] = src[j];
            j++;
        }
        dst[j] = '\0';
    }
    return (i);
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    char src[] = "Hello, World!";
    char dst[20];

    size_t len = ft_strlcpy(dst, src, sizeof(dst));

    printf("Copied string: %s\n", dst);
    printf("Length of src: %zu\n", len);

    return 0;
}