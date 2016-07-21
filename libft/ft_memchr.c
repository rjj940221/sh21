/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:48:13 by rojones           #+#    #+#             */
/*   Updated: 2016/05/13 11:04:47 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t	i;
	char	*so;

	i = 0;
	so = (char *)s;
	while (i < n && so[i] != '\0')
	{
		if (so[i] == c)
			return ((char *)&so[i]);
		i++;
	}
	if (so[i] == c)
		return ((char *)&so[i]);
	return (NULL);
}
