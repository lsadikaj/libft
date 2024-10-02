/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:44:08 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/02 14:10:49 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    if (argc < 2)
    {
        printf("Please write minimum a argument\n");
        return (1);
    }
    i = 1;
    while (i < argc)
    {
        size_t length = ft_strlen(argv[i]);
        printf("The length of \"%s\" is : %zu\n", argv[i], length);
        i++;
    }
    return (0);
}