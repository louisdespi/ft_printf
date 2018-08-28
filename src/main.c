/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:31:44 by louis             #+#    #+#             */
/*   Updated: 2018/08/28 15:17:50 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>

int		main(int argc, char **argv)
{
	int		i;
	i = 6;
	printf("printf   : [%d]\n", i);
	ft_printf("ft_printf: [%d]\n", i);
	//--------------
	printf("printf   : [%4d]\n", i);
	ft_printf("ft_printf: [%4d]\n", i);
	//--------------
	printf("printf   : [%+4d]\n", i);
	ft_printf("ft_printf: [%+4d]\n", i);
	//--------------
	printf("printf   : [%+d]\n", i);
	ft_printf("ft_printf: [%+d]\n", i);
	//--------------
	printf("printf   : [%-4d]\n", i);
	ft_printf("ft_printf: [%-4d]\n", i);
	//--------------
	printf("printf   : [%+-4d]\n", i);
	ft_printf("ft_printf: [%+-4d]\n", i);
	//--------------
return (0);
}
