/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:03:29 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/03 15:22:22 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

#include <stdio.h>

int main(void)
{
    char c = 'A';
    int i = 'A';
    int eof = EOF; // EOF est typiquement -1
    
    printf("c = %d, i = %d, eof = %d\n", c, i, eof);
    return (0);
}