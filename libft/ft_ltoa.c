/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:10:19 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/25 20:52:05 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_decimal_size(long n)
{
	int		size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

char			*ft_ltoa(long n)
{
	char	*to_ret;
	int		size;
	long	tmp;

	tmp = n;
	size = get_decimal_size(tmp);
	if (tmp < 0)
		size++;
	if (!(to_ret = (char*)malloc(sizeof(*to_ret) * (size + 1))))
		return (NULL);
	if (tmp < 0)
	{
		to_ret[0] = '-';
		tmp = -tmp;
	}
	to_ret[size] = '\0';
	to_ret[--size] = (tmp % 10) + 48;
	while (tmp /= 10)
		to_ret[--size] = (tmp % 10) + 48;
	return (to_ret);
}
