/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:26:47 by rojones           #+#    #+#             */
/*   Updated: 2016/05/11 17:36:35 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *const dst, const void *const src, int c, size_t n)
{
	size_t			i;
	const char		*srco;
	char			*dsto;
	unsigned char	test;

	srco = src;
	dsto = dst;
	test = c;
	i = 0;
	while (i < n)
	{
		if (srco[i] == test)
		{
			dsto[i] = srco[i];
			return (&dst[i + 1]);
		}
		dsto[i] = srco[i];
		i++;
	}
	return (NULL);
}
