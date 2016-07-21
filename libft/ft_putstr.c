/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:18:16 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:02:07 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putstrwide(wchar_t *s)
{
	size_t	end;
	size_t	i;
	char	c;

	end = ft_strlenwide(s);
	i = 0;
	while (i < end)
	{
		c = s[i++];
		ft_putchar(c);
	}
}
