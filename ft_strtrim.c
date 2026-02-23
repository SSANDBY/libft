/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:50:17 by melmbaz           #+#    #+#             */
/*   Updated: 2026/01/29 13:40:38 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (*s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	len_counter(char const *s1, char const *set, size_t *left_i,
		size_t *right_i)
{
	while (s1[*left_i])
	{
		if (checker(s1 + *left_i, set))
			(*left_i)++;
		else
			break ;
	}
	while (*right_i > *left_i && s1[*right_i])
	{
		if (checker(s1 + *right_i, set))
			(*right_i)--;
		else
			break ;
	}
	return ((*right_i) - (*left_i) + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*arr;
	size_t	left_i;
	size_t	right_i;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	i = 0;
	left_i = 0;
	right_i = ft_strlen(s1) - 1;
	len = len_counter(s1, set, &left_i, &right_i);
	if (left_i > right_i)
		return (ft_strdup(""));
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	while (left_i <= right_i)
		arr[i++] = s1[left_i++];
	arr[i] = '\0';
	return (arr);
}
