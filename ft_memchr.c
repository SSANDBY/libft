/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 01:41:08 by melmbaz           #+#    #+#             */
/*   Updated: 2026/01/29 13:39:10 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n == 0)
		return (NULL);
	while (*(unsigned char *)s++ != (unsigned char)c && --n)
		;
	if (*(unsigned char *)(s - 1) == (unsigned char)c)
		return ((void *)(s - 1));
	return (0);
}
