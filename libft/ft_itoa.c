/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:11:03 by rojones           #+#    #+#             */
/*   Updated: 2016/05/14 12:13:25 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intsize(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while ((n /= 10) > 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*re;
	int		size;

	size = ft_intsize(n);
	re = ft_strnew(size);
	if (re == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		re[0] = '-';
	}
	size--;
	while ((n / 10) > 0)
	{
		re[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	re[size] = (n % 10) + '0';
	return (re);
}
