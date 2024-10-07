/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:07:18 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/07 21:27:03 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
#include <stdlib.h>

void ft_lsclear(t_list **lst, void (*del)(void *))
{
    t_list  *temp;

    if (!lst || !del)
        return;
    while (*lst)
    {
        temp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = temp;
    }
    *lst = NULL;
}

#include <stdio.h>

void    del(void *content)
{
    free(content);
}

int main(void)
{
    t_list *head = ft_lstnew(malloc(10)); // Crée un premier élément avec du contenu alloué
    t_list *second = ft_lstnew(malloc(20)); // Crée un deuxième élément avec du contenu alloué

    ft_lstadd_back(&head, second); // Ajoute le deuxième élément à la liste

    // Test avant suppression
    printf("Before clear: head = %p, second = %p\n", (void *)head, (void *)second);

    ft_lstclear(&head, del_function); // Appelle la fonction pour tout supprimer

    // Test après suppression
    printf("After clear: head = %p\n", (void *)head); // Devrait afficher NULL

    return (0);
}