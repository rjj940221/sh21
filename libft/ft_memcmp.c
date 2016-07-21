/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:05:29 by rojones           #+#    #+#             */
/*   Updated: 2016/05/18 16:21:58 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	c1;

	i = 0;
	while (i < n)
	{
		c1 = *(unsigned char *)(s1 + i);
		c2 = *(unsigned char *)(s2 + i);
		i++;
		if (c1 != c2)
			return (c1 - c2);
	}
	return (0);
}
