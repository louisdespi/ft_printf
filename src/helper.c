/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:34:12 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/21 19:23:10 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_option(int c)
{
	return (c == '-' || c == '+' || c == '0' || c == '#' || c == ' ');
}

int		is_formspec(int c)
{
	return (c == 'd' || c == 'p' || c == 's' || c == 'o' || c == 'u' ||
			c == 'x' || c == 'c' || c == 'i' || c == 'D' || c == 'O' ||
			c == 'X');
}

int		is_length(int c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

int		is_bit_on(int c, int offset)
{
	return ((c>>offset)&1);
}
