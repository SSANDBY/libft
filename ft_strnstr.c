/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 02:39:01 by melmbaz           #+#    #+#             */
/*   Updated: 2026/01/29 13:40:29 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (len-- && *big)
	{
		i = 0;
		while ((big[i] == little[i]) && little_len <= len + 1)
		{
			i++;
			if (!little[i])
				return ((char *)(big));
		}
		big++;
	}
	return (NULL);
}
