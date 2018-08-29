/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:31:44 by louis             #+#    #+#             */
/*   Updated: 2018/08/29 23:02:13 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>

int		main(int argc, char **argv)
{
	//int		i;
	
	if (argc != 2)
		return (1);
	/*i = ft_atoi(argv[1]);
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
	printf("printf   : [%04d]\n", i);
	ft_printf("ft_printf: [%04d]\n", i);
	*/
	int		a;
	a = ft_atoi(argv[1]);
	ft_printf("[%#x]\n", a);
	printf("[%#x]\n", a);
	return (0);
}
