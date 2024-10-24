/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:32:25 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/23 10:50:10 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**s_split;
	size_t	i;
	size_t	j;

	s_split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s_split || !s)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			s_split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	s_split[j] = NULL;
	return (s_split);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**result;
	int		i;

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

	return (0);
}
*/