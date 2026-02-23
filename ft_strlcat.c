/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:11:47 by melmbaz           #+#    #+#             */
/*   Updated: 2026/01/07 00:50:54 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen((const char *)dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	else
	{
		while (dst_len + i < size - 1 && *src)
			dst[dst_len + i++] = *src++;
		dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}
