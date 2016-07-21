/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:38:35 by rojones           #+#    #+#             */
/*   Updated: 2016/05/13 10:50:40 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dsto;
	const char	*srco;

	if (len != 0 && dst != src)
	{
		i = 0;
		dsto = dst;
		srco = src;
		while (i < len && dsto && srco)
		{
			if (dsto != srco)
				*dsto = *srco;
			i++;
			dsto++;
			srco++;
		}
	}
	return (dst);
}
