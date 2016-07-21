/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 07:30:13 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:04:53 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list		vl;
	int			chrc;
	const char	*ft;
	int			wre;

	va_start(vl, format);
	ft = format;
	chrc = 0;
	wre = 0;
	while (*ft != '\0')
	{
		if (ft_lookflag((char *)ft, &chrc) == 1)
		{
			ft = ft_findflag((char *)ft, &chrc, vl);
			if (chrc == -1)
				wre = -1;
		}
		ft++;
	}
	va_end(vl);
	if (wre == -1)
		chrc = -1;
	return (chrc);
}

int		ft_lookflag(char *ft, int *chrc)
{
	if (*ft != '%')
	{
		ft_putchar(*ft);
		*chrc = *chrc + 1;
	}
	else if (*(ft + 1) != '%')
	{
		return (1);
	}
	else
	{
		*chrc = *chrc + 1;
		ft_putchar(*(++ft));
	}
	return (0);
}
