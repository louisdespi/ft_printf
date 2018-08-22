/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strforcejoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 20:25:03 by lode-spi          #+#    #+#             */
/*   Updated: 2018/08/22 20:36:06 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strforcejoin(char *s1, char *s2)
{
	char	*ret;
	char	*t;
	size_t	size;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ret = (char*)malloc(sizeof(*ret) * size)))
		return (NULL);
	t = ret;
	while (*s1)
		*ret++ = *s1++;
	while (*s2)
		*ret++ = *s2++;
	*ret = '\0';
	return (t);
}
