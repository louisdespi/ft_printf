/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 02:13:15 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/26 02:52:39 by lode-spi         ###   ########.fr       */
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

void	spec_D(t_field *field, va_list ap)
{
	field->value = ft_ltoa(va_arg(ap, long int));
	field->size_value = ft_strlen(field->value);
}

void	spec_d(t_field *field, va_list ap)
{
	field->value = ft_itoa(va_arg(ap, int));
	field->size_value = ft_strlen(field->value);
}

void	spec_s(t_field *field, va_list ap)
{
	field->value = va_arg(ap, char*);
	field->size_value = ft_strlen(field->value);
}

void	spec_p(t_field *field, va_list ap)
{
	field->value = ft_getaddress(va_arg(ap, void*));
	field->size_value = ft_strlen(field->value);
}

void	spec_o(t_field *field, va_list ap)
{
	field->value = ft_itoa_base(va_arg(ap, unsigned int), 8, 0);
	field->size_value = ft_strlen(field->value);
}

void	spec_O(t_field *field, va_list ap)
{
	field->value = ft_itoa_base(va_arg(ap, unsigned long), 8, 0);
	field->size_value = ft_strlen(field->value);
}

void	spec_u(t_field *field, va_list ap)
{
	field->value = ft_itoa_base(va_arg(ap, unsigned long), 10, 0);
	field->size_value = ft_strlen(field->value);
}

void	spec_x(t_field *field, va_list ap)
{
	field->value = ft_itoa_base(va_arg(ap, unsigned int), 16, 0);
	field->size_value = ft_strlen(field->value);
}

void	spec_X(t_field *field, va_list ap)
{
	field->value = ft_itoa_base(va_arg(ap, unsigned int), 16, 1);
	field->size_value = ft_strlen(field->value);
}

void	spec_c(t_field *field, va_list ap)
{
	if (!(field->value = (char*)malloc(sizeof(char) * 2)))
		return ;
	field->value[1] = '\0';
	field->value[0] = (char)va_arg(ap, unsigned int);
	field->size_value = 1;
}
