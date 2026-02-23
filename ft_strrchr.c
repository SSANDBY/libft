/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:27:26 by melmbaz           #+#    #+#             */
/*   Updated: 2026/01/29 13:40:34 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)(s + len));
	if (len == 0)
		return (NULL);
	s += len;
	s--;
	while (*s-- && len--)
	{
		if ((unsigned char)*(s + 1) == (unsigned char)c)
			return ((char *)(s + 1));
	}
	return (NULL);
}
