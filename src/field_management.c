/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 18:11:21 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/21 19:54:59 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_width(t_field *field)
{
	size_t	width;
	char	*ret;
	char	*tag;
	size_t	i;

	width = ft_max(field->size_value, field->width);
	if (!(ret = (char*)malloc(sizeof(*ret) * (width + 1))))
		return ;
	tag = ret;
	i = 0;
	while (i < width)
	{
		if (i < width - field->size_value)
			ret[i] = ' ';
		else
			ret[i] = *(field->value++);
		i++;
	}
	ret[i] = '\0';
	field->value = tag;
	field->size_value = width;
}

void	manage_options(t_field *field)
{
	char	*start;
	char	*end;

	if (is_bit_on(field->options, 0)) // "-"
	{
		printf("[-] -> Left-justify the result within the field width.\n");
	}
	if (is_bit_on(field->options, 1)) // "+"
	{
		printf("[+] -> Prefix the output value with a sign (+ or -) if the output value is of a signed type.\n");
	}
	if (is_bit_on(field->options, 2)) // "#"
	{
		printf("[#] -> This flag is unused on d specifier.\n");
	}
	if (is_bit_on(field->options, 3)) // "0"
	{
		printf("[0] -> the 0 flag causes leading 0s to pad the output to the field width. The 0 flag is ignored if precision is specified for an integer or if the - flag is specified.\n");
	}
	if (is_bit_on(field->options, 4)) // " "
	{
		printf("[ ] -> Prefix the output value with a blank if the output value is signed and positive. The + flag overrides the blank flag if both appear, and a positive signed value will be output with a sign.\n");
	}
}
