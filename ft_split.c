/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:16:04 by melmbaz           #+#    #+#             */
/*   Updated: 2026/01/30 13:58:06 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	word_counter;

	word_counter = 0;
	i = 0;
	if (c == '\0')
		return (ft_strlen(s) != 0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word_counter++;
		if (s[i] == c)
			while (s[i] == c)
				i++;
		else
			i++;
	}
	return (word_counter);
}

static void	word_filler(char *arr, char *each_word_add, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		arr[j] = each_word_add[j];
		j++;
	}
	arr[j] = '\0';
}

static char	*inner_malloc_maker(char **each_words_add, char c, int *bool)
{
	size_t	words_length;
	size_t	i;
	char	*arr;
	char	*word_start;

	i = 0;
	if (c == '\0')
		words_length = ft_strlen(*each_words_add);
	else
	{
		while (**each_words_add == c)
			(*each_words_add)++;
		while ((*each_words_add)[i] != c && (*each_words_add)[i] != '\0')
			i++;
		words_length = i;
	}
	word_start = *each_words_add;
	*each_words_add += words_length;
	while (**each_words_add == c)
		(*each_words_add)++;
	arr = malloc(words_length + 1);
	if (!arr)
		return (*bool = 1, NULL);
	return (word_filler(arr, word_start, words_length), arr);
}

static void	free_mal(int parent_index, char **parent_malloc)
{
	int	i;

	i = 0;
	while (i < parent_index)
		free(parent_malloc[i++]);
	free(parent_malloc);
}

char	**ft_split(char const *s, char c)
{
	char	**parent_malloc;
	size_t	parent_index;
	char	*each_words_add;
	int		bool;
	size_t	word_cnt;

	if (!s)
		return (NULL);
	word_cnt = word_count(s, c);
	bool = 0;
	each_words_add = (char *)s;
	parent_index = 0;
	parent_malloc = malloc(sizeof(char *) * (word_cnt + 1));
	if (!parent_malloc)
		return (NULL);
	while (parent_index < word_cnt)
		parent_malloc[parent_index++] = inner_malloc_maker(&each_words_add, c,
				&bool);
	parent_malloc[parent_index] = NULL;
	if (bool)
		return (free_mal(parent_index, parent_malloc), NULL);
	return (parent_malloc);
}
