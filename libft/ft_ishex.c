/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 10:01:30 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:31:14 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_ishex(char c)
{
	char	*refl;
	char	*refu;
	int		re;
	int		i;

	refl = "0123456789abcdef";
	refu = "0123456789ABCDEF";
	re = -1;
	i = 0;
	while (refl[i] != '\0' && re == -1)
	{
		if (c == refl[i])
			re = i;
		i++;
	}
	i = 0;
	while (refu[i] != '\0' && re == -1)
	{
		if (c == refu[i])
			re = i;
		i++;
	}
	return (re);
}
