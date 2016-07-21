/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 08:00:31 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:09:36 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(va_list vl, t_mod mod)
{
	int		re;
	char	s[2];

	s[0] = va_arg(vl, int);
	s[1] = '\0';
	re = 0;
	if (mod.pos == 1)
		mod.pos = 0;
	ft_stringformat(s, &mod);
	ft_padwidth(&mod, &re, 's');
	ft_pad(s, &mod, &re);
	return (re);
}
