/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:42:21 by rojones           #+#    #+#             */
/*   Updated: 2016/05/14 12:02:33 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size;
	char			*re;
	unsigned int	i;

	size = ft_strlen(s);
	re = ft_memalloc(size);
	i = 0;
	if (re != NULL)
	{
		while (i < size)
		{
			re[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (re);
}
