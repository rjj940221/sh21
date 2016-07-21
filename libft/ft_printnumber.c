/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:12:35 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:08:32 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_pickconvert(va_list vl, int c, t_mod mod)
{
	int	re;

	re = 0;
	if (ft_checklenmod(&mod) == 0)
	{
		if (c == 'i' || c == 'd')
			re = ft_prepconvert(va_arg(vl, int), 10, c, &mod);
		else if (c == 'o')
			re = ft_unconvert(va_arg(vl, unsigned int), 8, c, &mod);
		else if (c == 'x' || c == 'X')
			re = ft_unconvert(va_arg(vl, unsigned int), 16, c, &mod);
		else if (c == 'u')
			re = ft_unconvert(va_arg(vl, unsigned int), 10, c, &mod);
	}
	else
		re = ft_picklencon(vl, c, mod);
	return (re);
}

int			ft_picklencon(va_list vl, int c, t_mod mod)
{
	int	re;

	re = 0;
	if (c == 'i' || c == 'd')
		re = ft_unconvert(ft_lenmod(&mod, vl, c), 10, c, &mod);
	else if (c == 'o')
		re = ft_unconvert(ft_lenmod(&mod, vl, c), 8, c, &mod);
	else if (c == 'x' || c == 'X')
		re = ft_unconvert(ft_lenmod(&mod, vl, c), 16, c, &mod);
	else if (c == 'u')
		re = ft_unconvert(ft_lenmod(&mod, vl, c), 10, c, &mod);
	return (re);
}

uintmax_t	ft_oxulenmod(t_mod *mod, va_list vl)
{
	uintmax_t	re;
	char		c;

	re = 0;
	if (mod->l > 0)
		re = va_arg(vl, unsigned long);
	if (mod->ll > 0)
		re = va_arg(vl, unsigned long long);
	if (mod->h > 0)
		re = (unsigned short)(va_arg(vl, int));
	if (mod->hh > 0)
	{
		c = va_arg(vl, int);
		re = (unsigned char)c;
	}
	if (mod->j > 0)
		re = va_arg(vl, uintmax_t);
	if (mod->z > 0)
		re = va_arg(vl, size_t);
	return (re);
}

uintmax_t	ft_lenmod(t_mod *mod, va_list vl, int c)
{
	uintmax_t	re;

	if (c != 'd' || c != 'i')
		re = ft_oxulenmod(mod, vl);
	else
	{
		if (mod->l > 0)
			re = va_arg(vl, long);
		if (mod->ll > 0)
			re = va_arg(vl, long long);
		if (mod->h > 0)
			re = (short)(va_arg(vl, int));
		if (mod->hh > 0)
			re = (signed char)(va_arg(vl, int));
		if (mod->j > 0)
			re = va_arg(vl, intmax_t);
		if (mod->z > 0)
			re = va_arg(vl, signed long);
	}
	return (re);
}

int			ft_checklenmod(t_mod *mod)
{
	if (mod->l > 0)
		return (1);
	if (mod->ll > 0)
		return (1);
	if (mod->h > 0)
		return (1);
	if (mod->hh > 0)
		return (1);
	if (mod->j > 0)
		return (1);
	if (mod->z > 0)
		return (1);
	return (0);
}
