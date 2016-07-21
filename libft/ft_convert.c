/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:42:08 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:06:49 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unconvert(uintmax_t num, int base, int c, t_mod *mod)
{
	int			re;
	static char	*rep;
	static char	buffer[50];
	char		*ptr;

	mod->pos = 0;
	re = 0;
	ptr = &buffer[49];
	rep = "0123456789ABCDEF";
	if (c == 'x')
		rep = "0123456789abcdef";
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		*--ptr = rep[num % base];
		num /= base;
		ft_incramentmod(mod);
	}
	ft_printnum(ptr, mod, &re, c);
	return (re);
}

int		ft_prepconvert(int num, int base, int c, t_mod *mod)
{
	int		re;
	char	*nums;

	re = 0;
	nums = ft_convert(num, base, mod);
	ft_printnum(nums, mod, &re, c);
	return (re);
}

char	*ft_convert(int num, int base, t_mod *mod)
{
	static char *rep;
	static char buffer[50];
	char		*ptr;
	int			neg;

	neg = 0;
	ptr = &buffer[49];
	rep = "0123456789";
	if (num < 0 && (neg = 1) == 1)
	{
		mod->space = 0;
		num *= -1;
	}
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		*--ptr = rep[num % base];
		ft_incramentmod(mod);
		num /= base;
	}
	if (neg == 1)
		*--ptr = '-';
	return (ptr);
}

void	ft_printnum(char *s, t_mod *mod, int *chrc, int c)
{
	ft_padwidth(mod, chrc, c);
	ft_nummoders(mod, chrc, c);
	ft_pad(s, mod, chrc);
}

void	ft_incramentmod(t_mod *mod)
{
	mod->zero--;
	mod->neg--;
	mod->pre--;
	mod->width--;
}
