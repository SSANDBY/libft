/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:10:28 by melmbaz           #+#    #+#             */
/*   Updated: 2026/01/29 13:40:42 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	temp_start;
	char	*arr;

	if (!s)
		return (NULL);
	temp_start = ft_strlen(s);
	if (start >= temp_start)
		return (ft_strdup(""));
	if (len > temp_start - start)
		len = temp_start - start;
	arr = (char *)malloc((sizeof(char) * len) + 1);
	if (!arr)
		return (NULL);
	temp_start = 0;
	while (len--)
		arr[temp_start++] = s[start++];
	arr[temp_start] = '\0';
	return (arr);
}
