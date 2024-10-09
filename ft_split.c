/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadikaj <lsadikaj@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:32:25 by lsadikaj          #+#    #+#             */
/*   Updated: 2024/10/09 14:11:57 by lsadikaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_word_dup(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	fill_split(char const *s, char c, char **split)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = -1;
	while (s[i])
	{
		if (s[i] != c && start == -1)
		{
			start = i;
		}
		else if (s[i] == c && start != -1)
		{
			split[j++] = ft_word_dup(s, start, i);
			start = -1;
		}
		else if (s[i + 1] == '\0' && start != -1)
		{
			split[j++] = ft_word_dup(s, start, i + 1);
		}
		i++;
	}
	split[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	fill_split(s, c, split);
	return (split);
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