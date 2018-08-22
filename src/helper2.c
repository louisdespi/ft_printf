/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:49:07 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/22 20:58:30 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	left_justify(t_field *field)
{
	char	*s;
	char	*start;
	char	*end;
	size_t	total_size;
	size_t	space_amount;

	s = field->value;
	end = field->value;
	start = field->value;
	while (*end)
		end++;
	total_size = end - start;
	while (*start == ' ')
		start++;
	space_amount = total_size - (end - start);
	while (*start)
	{
		*s++ = *start++;
	}
	while (space_amount--)
		*s++ = ' ';
	*s = '\0';
}

void	prefix_value(t_field *field, char *prefix)
{
	char	*s;
	char	*start;
	char	*end;
	char	sign;

	int		test;

	if (ft_atoi(field->value) < 0)
		return ;
	s = field->value;
	if ((test = field->width - (int)ft_strlen(prefix)) > (int)field->size_value)
	{
		printf("DEBUG : %d\n", test);
		if (is_bit_on(field->options, 0))
		{
			ft_memmove(s + ft_strlen(prefix), s, field->size_value);
			field->value = ft_strforcejoin(prefix, field->value);
		}
		else
		{
			while (*s == ' ')
				s++;
			*(--s) = '+';
		}
	}
	else
	{
		printf("Il faut remallocer l'espace avec un octet de plus pour aller poser le signe avant le nombre.\n");
	}
}
