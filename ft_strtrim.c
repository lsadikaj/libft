/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:26:40 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/09 12:48:26 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed;

	if (!s1 || !set || set[1] != '\0')
		return (NULL);
	start = 0;
	while (s1[start] && (s1[start] == set[0] || s1[start] == ' '))
		start++;
	end = ft_strlen(s1);
	while (end > start && (s1[end - 1] == set[0] || s1[end - 1] == ' '))
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
/*
#include <stdio.h>

int main(void)
{
	char	*result;

	result = ft_strtrim("   Hello World!   ", " ");
	printf("Test 1: '%s'\n", result);
	free(result);

	result = ft_strtrim("Hello World!", " ");
	printf("Test 2: '%s'\n", result);
	free(result);

	result = ft_strtrim("###Hello World!###", "#");
	printf("Test 3: '%s'\n", result);
	free(result);

	result = ft_strtrim("Hello World!", "H");
	printf("Test 4: '%s'\n", result);
	free(result);

	result = ft_strtrim("", " ");
	printf("Test 5: '%s'\n", result);
	free(result);

	result = ft_strtrim("###", "#");
	printf("Test 6: '%s'\n", result);
	free(result);

	result = ft_strtrim("  ##Hello World!##  ", "#"); 
	printf("Test 7: '%s'\n", result);
	free(result);

	result = ft_strtrim("Hello World!", "##"); 
	printf("Test 8: '%s'\n", result ? result : "NULL");

	return (0);
}
*/