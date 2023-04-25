/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:37:00 by csenand           #+#    #+#             */
/*   Updated: 2023/04/24 23:02:31 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	DESCRIPTION
** 	Allocates (with malloc(3)) and returns an array of strings obtained
** 	by splitting ’s’ using the character ’c’ as a delimiter. 
** 	Takes a string and splint them into substr and make an array with it.
**	The array must end with a NULL pointer.
**	
**	PARAMETERS
**	s: The string to be split.
**	c: The delimiter character.
**	
**	RETURN VALUE
**	The array of new strings resulting from the split.
**	NULL if the allocation fails.
*/

// Separates the string into substrings, splitting the string into substrings
// based on the separator characters (i.e separators).  The function returns an
// array of pointers to strings, dynamically allocated on the heap, and it
// effectively "returns" the number of these strings via pass-by-pointer using
// the parameter count.

#include "../include/libft.h"

static int	ft_countwords(const char *str, char c)
{
	int		trigger;
	size_t	nb_words;

	trigger = 0;
	nb_words = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			nb_words++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (nb_words);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	*clear(char **words_array)
{
	int	i;

	i = 0;
	while (words_array && words_array[i])
	{
		free(words_array[i]);
		i++;
	}
	free(words_array);
	return (NULL);
}

static int	split_s(char **words_array, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			words_array[j] = word_dup(s, k, i);
			if (!words_array[j])
				return (0);
			j++;
			k = -1;
		}
		i++;
	}
	words_array[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words_array;

	words_array = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!s || !words_array)
		return (NULL);
	if (!split_s(words_array, s, c))
		return (clear(words_array));
	return (words_array);
}
