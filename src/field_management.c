/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 18:11:21 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/29 23:14:00 by lode-spi         ###   ########.fr       */
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

void	option_0(t_field *field) //option "-"
{
	if (is_bit_on(field->options, 0)) // if option "-" is set
		field->value = ft_strforcejoin(field->value, get_width_str(field));
	else
		field->value = ft_strforcejoin(get_width_str(field), field->value);
}

void	option_1(t_field *field) //option "+"
{
	if (!is_bit_on(field->options, 1))
		return ;
	if (ft_atoi(field->value) > 0)
	{
		field->value = ft_strforcejoin("+", field->value);
		field->size_value = ft_strlen(field->value);
	}
}

void	option_2(t_field *field) //option "#"
{
	if (!is_bit_on(field->options, 2))
		return ;
	if (field->init_value == 0)
		return ;
	if (field->formspec == 'x')
		field->value = ft_strforcejoin("0x", field->value);
	if (field->formspec == 'X')
		field->value = ft_strforcejoin("0X", field->value);
	if (field->formspec == 'o' || field->formspec == 'O')
		field->value = ft_strforcejoin("0", field->value);
	field->size_value = ft_strlen(field->value);
}

void	option_3(t_field *field) //option "0"
{
	char	*t;
	int		amount;
	int		i;
	char	sign;

	if (!is_bit_on(field->options, 3))
		return ;
	if (is_bit_on(field->options, 0))
		return ;
	if (field->width - field->size_value <= 0)
		return ;
	t = field->value;
	amount = field->width - field->size_value;
	sign = cut_sign(field);
	if (sign != 0)
		*t++ = sign;
	i = -1;
	while (++i < amount)
		*t++ = '0';
}

void	option_4(t_field *field) //option " "
{
	if (!is_bit_on(field->options, 4))
		return ;
	if (is_bit_on(field->options, 1))
		return ;
	if (ft_atoi(field->value) <= 0)
		return ;
	field->value = ft_strforcejoin(" ", field->value);
	field->size_value = ft_strlen(field->value);
}

