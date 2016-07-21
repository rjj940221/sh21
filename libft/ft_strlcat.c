/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:05:56 by rojones           #+#    #+#             */
/*   Updated: 2016/05/14 11:28:48 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *const dst, const char *const src, size_t len)
{
	int srci;
	int end;
	int jump;

	srci = 0;
	if (ft_strlen(dst) > len)
		return (len + ft_strlen(src));
	end = (int)len - ft_strlen(dst) - 1;
	jump = ft_strlen(dst);
	while (srci < end)
	{
		dst[srci + jump] = src[srci];
		srci++;
	}
	dst[srci + jump] = '\0';
	return ((size_t)(srci + jump));
}
