/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 02:13:15 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/29 23:13:27 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	(*get_func(char c))(t_field *field, va_list ap)
{
	int		i;

	i = 0;
	while (g_tab[i].key != -1)
	{
		if (g_tab[i].key == c)
			return (g_tab[i].f);
		i++;
	}
	return (NULL);
}

void	do_options(t_field *field)
{
	option_1(field);
	option_4(field);
	option_2(field);
	option_0(field);
	option_3(field);
}

void	spec_D(t_field *field, va_list ap)
{
	field->init_value = va_arg(ap, long int);
	if (!(field->value = ft_ltoa(field->init_value)))
		return ;
	field->size_value = ft_strlen(field->value);
	do_options(field);
}

void	spec_d(t_field *field, va_list ap)
{
	field->init_value = va_arg(ap, int);
	if (!(field->value = ft_itoa(field->init_value)))
		return ;
	field->size_value = ft_strlen(field->value);
	do_options(field);
}

void	spec_s(t_field *field, va_list ap)
{
	field->init_value = 0;
	field->value = va_arg(ap, char*);
	field->size_value = ft_strlen(field->value);
	do_options(field);
}

void	spec_p(t_field *field, va_list ap)
{
	field->init_value = 0;
	field->value = ft_getaddress(va_arg(ap, void*));
	field->size_value = ft_strlen(field->value);
	do_options(field);
}

void	spec_o(t_field *field, va_list ap)
{
	field->init_value = va_arg(ap, unsigned int);
	field->value = ft_itoa_base(field->init_value, 8, 0);
	field->size_value = ft_strlen(field->value);
	do_options(field);
}

void	spec_O(t_field *field, va_list ap)
{
	field->init_value = va_arg(ap, unsigned long);
	field->value = ft_itoa_base(field->init_value, 8, 0);
	field->size_value = ft_strlen(field->value);
	do_options(field);
}

void	spec_u(t_field *field, va_list ap)
{
	field->init_value = va_arg(ap, unsigned long);
	field->value = ft_itoa_base(field->init_value, 10, 0);
	field->size_value = ft_strlen(field->value);
	do_options(field);
}

void	spec_x(t_field *field, va_list ap)
{
	field->init_value = va_arg(ap, unsigned int);
	field->value = ft_itoa_base(field->init_value, 16, 0);
	field->size_value = ft_strlen(field->value);
	do_options(field);
}

void	spec_X(t_field *field, va_list ap)
{
	field->init_value = va_arg(ap, unsigned int);
	field->value = ft_itoa_base(field->init_value, 16, 1);
	field->size_value = ft_strlen(field->value);
	do_options(field);
}

void	spec_c(t_field *field, va_list ap)
{
	field->init_value = 0;
	if (!(field->value = (char*)malloc(sizeof(char) * 2)))
		return ;
	field->value[1] = '\0';
	field->value[0] = (char)va_arg(ap, unsigned int);
	field->size_value = 1;
	do_options(field);
}
