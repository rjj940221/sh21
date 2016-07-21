/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:31:17 by rojones           #+#    #+#             */
/*   Updated: 2016/05/11 17:56:57 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*loop;

	loop = dst;
	while (len > 0 && *src != '\0')
	{
		*loop++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*loop++ = '\0';
		len--;
	}
	return (dst);
}
