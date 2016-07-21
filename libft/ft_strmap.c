/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:42:21 by rojones           #+#    #+#             */
/*   Updated: 2016/05/14 11:52:27 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	char	*re;
	size_t	i;

	size = ft_strlen(s);
	re = ft_memalloc(size);
	i = 0;
	if (re != NULL)
	{
		while (i < size)
		{
			re[i] = (*f)(s[i]);
			i++;
		}
	}
	return (re);
}
