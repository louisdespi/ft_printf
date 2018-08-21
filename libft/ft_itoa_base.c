/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 03:17:11 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/25 23:57:41 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*build_connexion(int base, int maj)
{
	char	*ret;
	int		i;

	if (!(ret = (char*)malloc(sizeof(*ret) * (base + 1))))
		return (NULL);
	i = 0;
	while (i < base)
	{
		if (i > 9)
		{
			if (maj)
				ret[i] = i + 55;
			else
				ret[i] = i + 87;
		}
		else
			ret[i] = i + 48;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		*ft_itoa_base(unsigned long nb, unsigned int base, int maj)
{
	int		size;
	long	tmp;
	char	*ret;
	int		i;
	char	*connexion;

	connexion = build_connexion(base, maj);
	tmp = nb;
	size = (nb == 0) ? 1 : 0;
	while (tmp > 0)
	{
		tmp /= base;
		size++;
	}
	if (!(ret = (char*)malloc(sizeof(*ret) * (size + 1))))
		return (NULL);
	ret[size] = '\0';
	i = --size;
	tmp = nb;
	while (i >= 0)
	{
		ret[i--] = connexion[tmp % base];
		tmp /= base;
	}
	return (ret);
}
