/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchartable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:10:36 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/25 20:14:05 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printchartable(char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(*s++);
		i++;
	}
}