/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 09:01:54 by exam              #+#    #+#             */
/*   Updated: 2016/07/08 11:51:56 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int nbr, int base)
{
	int	re;

	re = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		re++;
	}
	return (re);
}

char		*ft_itoa_base(int nbr, int base)
{
	int		numlen;
	int		sign;
	char	*re;
	char	*ref;

	numlen = ft_numlen(nbr, base);
	sign = 1;
	ref = "0123456789ABCDEF";
	if (nbr < 0 && (sign = -1) == -1)
		if (base == 10)
			numlen++;
	if (!(re = (char*)malloc(sizeof(char) * (numlen + 1))))
		return (NULL);
	re[numlen--] = '\0';
	if (nbr == 0)
		re[numlen] = '0';
	while (nbr != 0)
	{
		re[numlen--] = ref[(sign * (nbr % base))];
		nbr /= base;
	}
	if (sign == -1 && base == 10)
		re[0] = '-';
	return (re);
}
