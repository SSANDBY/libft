/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmbaz <melmbaz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:19:25 by melmbaz           #+#    #+#             */
/*   Updated: 2026/01/29 13:38:04 by melmbaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_len_cal(int *len, int *sign, int *n, int *temp_n)
{
	(*len) = 0;
	(*sign) = 1;
	if (*n < 0)
	{
		(*sign) = (*sign) * (-1);
		(*n) *= (*sign);
		(*len)++;
	}
	(*temp_n) = (*n);
	while (*temp_n)
	{
		(*temp_n) = (*temp_n) / 10;
		(*len)++;
	}
}

static int	edge_case_control(int n, char **arr)
{
	if (n == -2147483648)
	{
		*arr = ft_strdup("-2147483648");
		return (1);
	}
	if (n == 0)
	{
		*arr = ft_strdup("0");
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	int		len;
	int		temp_n;
	int		sign;
	char	*arr;

	ft_len_cal(&len, &sign, &n, &temp_n);
	if (edge_case_control(n, &arr))
		return (arr);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	while (len > 0)
	{
		len--;
		arr[len] = ((n % 10) + '0');
		n = n / 10;
	}
	if (sign == -1)
		arr[len] = '-';
	return (arr);
}
