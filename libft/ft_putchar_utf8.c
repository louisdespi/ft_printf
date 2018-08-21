/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_utf8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 05:30:52 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/30 18:18:52 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MASK(fcase, i) (0x3F >> ((fcase - 1) * (i == 0)))
#define COMB(fcase, i) (0x80 | ((0xF0 << (4 - fcase)) * (i == 0)))

static int				get_requestedbits(int n)
{
	int		i;

	i = 0;
	while ((n & 0x80000000) >> 31 != 1)
	{
		n <<= 1;
		i++;
	}
	return (32 - i);
}

static int				get_case(int n)
{
	int		rq;

	rq = get_requestedbits(n);
	if (rq < 8)
		return (1);
	if (rq < 12)
		return (2);
	if (rq < 17)
		return (3);
	return (4);
}

static unsigned char	*getcode_utf8(int n)
{
	int				f;
	unsigned char	*c;
	int				i;

	f = get_case(n);
	if (!(c = (unsigned char*)malloc(sizeof(*c) * (f + 1))))
		return (NULL);
	i = -1;
	if (f == 1)
		c[0] = n & 0xFF;
	else
		while (++i < f)
			c[i] = (((n >> (((f - 1) - i) * 6) & MASK(f, i)) | COMB(f, i)));
	c[f] = 0;
	return (c);
}

void					ft_putchar_utf8(int n)
{
	unsigned char	*c;
	unsigned char	*tmp;

	c = getcode_utf8(n);
	tmp = c;
	while (*tmp)
	{
		write(1, &(*tmp), 1);
		tmp++;
	}
	free(c);
	c = NULL;
}
