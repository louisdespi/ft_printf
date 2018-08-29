/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 04:50:03 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/29 20:10:01 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_list		*list;
	t_field		*curr;

	//ft_putendl("DEBUG : Starting ft_printf function.");
	list = NULL;
	list = build_list(format);
	va_start(ap, format);
	//print_list(list);
	process_list(list, ap);
	print_list(list);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			curr = ((t_field*)list->content);
			ft_printchartable(curr->value, ft_max(curr->size_value, curr->width));
			format += (curr->size);
			list = list->next;
		}
		else if (*format == '%' && *(format + 1) == '%')
			ft_putchar(*format++);
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (0);
}
