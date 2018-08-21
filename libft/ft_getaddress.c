/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:13:20 by louis             #+#    #+#             */
/*   Updated: 2018/07/25 23:58:29 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getaddress(void *addr)
{
	char	*hexpart;
	char	*ret;
	char	*tag;

	if (!(hexpart = ft_itoa_base((unsigned long)addr, 16, 0)))
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(*hexpart) * ((ft_strlen(hexpart) + 3)))))
		return (NULL);
	tag = ret;
	*ret++ = '0';
	*ret++ = 'x';
	while (*hexpart)
		*ret++ = *hexpart++;
	*ret = '\0';
	return (tag);
}
