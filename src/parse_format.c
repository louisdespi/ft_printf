/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:10:24 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/21 19:40:31 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_options(const char *restrict *format)
{
	char	c;

	c = 0;
	while (**format && is_option(**format))
	{
		if (**format == '-')
			c |= 1;
		if (**format == '+')
			c |= 2;
		if (**format == '#')
			c |= 4;
		if (**format == '0')
			c |= 8;
		if (**format == ' ')
			c |= 16;
		(*format)++;
	}
	return (c);
}

int		get_width(const char *restrict *format)
{
	int		ret;

	ret = 0;
	while (**format && **format >= 48 && **format <= 57)
	{
		ret = (ret * 10) + **format - 48;
		(*format)++;
	}
	return (ret);
}

int		get_precision(const char *restrict *format)
{
	int		ret;

	ret = 0;
	if (**format == '.')
	{
		(*format)++;
		while (**format && **format >= 48 && **format <= 57)
		{
			ret = (ret * 10) + **format - 48;
			(*format)++;
		}
	}
	return (ret);
}

char	get_length(const char *restrict *format)
{
	char	ret;

	ret = 0;
	if (**format == 'h' && *(*format + 1) != 'h')
		ret = 1;
	else if (**format == 'h' && *(*format + 1) == 'h')
		ret = 2;
	else if (**format == 'l' && *(*format + 1) != 'l')
		ret = 3;
	else if (**format == 'l' && *(*format + 1) == 'l')
		ret = 4;
	else if (**format == 'j')
		ret = 5;
	else if (**format == 'z')
		ret = 6;
	while (**format && is_length(**format))
		(*format)++;
	return (ret);
}

char	get_specif(const char *restrict *format)
{
	if (**format && is_formspec(**format))
		return (**format);
	return (0);
}
