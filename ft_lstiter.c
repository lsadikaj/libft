/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:35:43 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/10 11:24:18 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

void	print_content(void *content)
{
	printf("%s\n", (char *)content); // Cast du contenu en char* et l'affiche
}

int	main(void)
{
	t_list *head = ft_lstnew("Hello");
	t_list *second = ft_lstnew("World");
	t_list *third = ft_lstnew("!");

	ft_lstadd_back(&head, second);
	ft_lstadd_back(&head, third);

	printf("List contents:\n");
	ft_lstiter(head, print_content); // Itère et affiche chaque contenu de la liste

	return (0);
}
*/