/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 18:11:21 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/28 15:09:56 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_width_str(t_field *field)
{
	size_t	excess;
	char	*ret;
	char	*tag;

	if (field->width <= field->size_value)
		return (NULL);
	excess = field->width - field->size_value;
	if (!(ret = (char*)malloc(sizeof(*ret) * (excess + 1))))
		return (NULL);
	tag = ret;
	while (excess--)
		*ret++ = ' ';
	*ret = '\0';
	return (tag);
}

void	option_0(t_field *field)
{
	if (is_bit_on(field->options, 0)) // if option "-" is set
		field->value = ft_strforcejoin(field->value, get_width_str(field));
	else
		field->value = ft_strforcejoin(get_width_str(field), field->value);
}

void	option_1(t_field *field)
{
	if (is_bit_on(field->options, 1))
	{
		if (ft_atoi(field->value) > 0)
		{
			field->value = ft_strforcejoin("+", field->value);
			field->size_value = ft_strlen(field->value);
		}
	}
}
