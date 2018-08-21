/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 18:07:25 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/30 18:07:25 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:34:07 by louis             #+#    #+#             */
/*   Updated: 2018/07/30 18:05:37 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *
 * sSpdDioOuUxXcC
 * 
 * */

t_field			*parse_formspec(const char *restrict *format)
{
	t_field		*field;

	if (!(field = (t_field*)malloc(sizeof(*field))))
		return (NULL);
	field->options = get_options(format);
	field->width = get_width(format);
	field->precision = get_precision(format);
	field->length = get_length(format);
	field->formspec = get_specif(format);
	return (field);
}

/*t_list			*build_list(const char *restrict format)
{
	t_field		*field;
	t_list		*list;
	t_list		*ret;
	int			size;

	list = NULL;
	while (*format)
	{
		if (*format == '%' && *format + 1 != '%')
		{
			size = 1;
			while (*format && !(is_formspec(*format)))
			{
				format++;
				if (is_formspec(*format))
				{
					if (!(field = (t_field*)malloc(sizeof(*field))))
						return (NULL);
					field->formspec = *format;
					field->size = size;
					field->value = NULL;
					ret = ft_lstnew(field, sizeof(*field));
					ft_lstaddback(&list, ret);
					break;
				}
				size++;
			}
		}
		format++;
	}
	return (list);
}*/

t_list			*build_list(const char *restrict format)
{
	t_field					*field;
	t_list					*list;
	t_list					*new_elt;
	const char	*restrict	save;

	list = NULL;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			save = format;
			format++;
			field = parse_formspec(&format);
			field->size = format - save;
			field->value = NULL;
			if (!(new_elt = ft_lstnew(field, sizeof(*field))))
				return (NULL);
			ft_lstaddback(&list, new_elt);
		}
		format++;
	}
	return (list);
}

void			process_list(t_list *list, va_list ap)
{
	t_field		*field;

	while (list)
	{
		field = ((t_field*)list->content);
		get_func(field->formspec)(field, ap);
		list = list->next;
	}
}

void			print_list(t_list *list)
{
	t_field		*field;
	int			i;

	ft_putendl("__LIST__");
	while (list)
	{
		field = ((t_field*)list->content);
		ft_putendl("-----");
		ft_putstr("formspec : ");
		ft_putchar(field->formspec);
		ft_putchar('\n');
		ft_putstr("size : ");
		ft_putnbr(field->size);
		ft_putchar('\n');
		ft_putstr("value : ");
		if (field->value)
			ft_putendl(field->value);
		else
			ft_putendl("NULL");
		ft_putstr("size_value : ");
		ft_putnbr((int)field->size_value);
		ft_putchar('\n');
		ft_putstr("options : ");
		i = 0;
		while (i < 8)
		{
			ft_putchar(((field->options >> (7-i) & 1) + 48));
			i++;
		}
		ft_putchar('\n');
		ft_putstr("width : ");
		ft_putnbr(field->width);
		ft_putchar('\n');
		ft_putstr("Precision : ");
		ft_putnbr(field->precision);
		ft_putchar('\n');
		ft_putstr("Length : ");
		ft_putnbr(field->length);
		ft_putchar('\n');
		ft_putendl("-----");
		list = list->next;
	}
	ft_putendl("__END_OF_LIST__");
}
