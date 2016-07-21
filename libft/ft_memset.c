/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 08:06:58 by rojones           #+#    #+#             */
/*   Updated: 2016/05/11 16:08:04 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	rec;
	char	*alius;
	size_t	i;

	rec = c;
	i = 0;
	alius = b;
	while (i < len)
	{
		alius[i] = rec;
		i++;
	}
	return (b);
}
