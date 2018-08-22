/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:31:44 by louis             #+#    #+#             */
/*   Updated: 2018/08/22 20:53:34 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>

int		main(int argc, char **argv)
{
	int		i;
	i = 6;
	printf("printf   : [%-+4d]\n", i);
	ft_printf("ft_print : [%-+d]\n", i);
	return (0);
}
