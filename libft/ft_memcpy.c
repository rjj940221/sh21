/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 08:36:53 by rojones           #+#    #+#             */
/*   Updated: 2016/05/11 17:34:57 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *const dst, const void *const src, size_t n)
{
	char		*dsto;
	const char	*srco;
	size_t		i;

	i = 0;
	dsto = dst;
	srco = src;
	while (i < n)
	{
		dsto[i] = srco[i];
		i++;
	}
	return (dst);
}
