/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:40:29 by rojones           #+#    #+#             */
/*   Updated: 2016/05/14 11:44:48 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*re;
	char	*set;

	if (!(re = malloc(size)))
		return (NULL);
	set = (char *)re;
	*set = '\0';
	return (re);
}
