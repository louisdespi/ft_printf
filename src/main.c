/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:31:44 by louis             #+#    #+#             */
/*   Updated: 2018/07/30 18:18:51 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>

int		main(int argc, char **argv)
{
	int i;
	//ft_printf("Salut je suis %+-#40.4hhs. J'ai %d ans.\nAdresse de i : %p", "Louis", 24, &i);
	ft_putchar_utf8(317);
	return (0);
}
