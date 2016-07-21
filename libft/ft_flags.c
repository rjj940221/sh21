/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:32:50 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:09:14 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_findflag(char *s, int *chrc, va_list vl)
{
	char	*temp;
	t_mod	mod;

	ft_initmod(&mod);
	temp = s;
	while (ft_isflaglo(*temp, chrc, vl, mod) == 0 &&
			ft_isflagup(*temp, chrc, vl, &mod) == 0 && *temp)
	{
		if (ft_isdigit(*temp) == 1 || *temp == '.' || *temp == '-')
			temp = ft_getnum(temp, &mod);
		else
		{
			ft_addmod(*temp, &mod);
			temp++;
		}
	}
	return (temp);
}

char	*ft_getnum(char *s, t_mod *mod)
{
	char	c;
	char	*num;
	char	temp[2];

	c = *s;
	num = "";
	if (ft_isdigit(c) == 0 || c == '0')
		s++;
	temp[1] = '\0';
	while (*s && ft_isdigit(*s) == 1)
	{
		temp[0] = *s++;
		num = ft_strjoin(num, temp);
	}
	if (c == '.' || c == '-')
		mod->zero = 0;
	if (c == '0' && mod->pre == -1)
		mod->zero = ft_atoi(num);
	if (c == '.')
		mod->pre = ft_atoi(num);
	if (c == '-')
		mod->neg = ft_atoi(num);
	if (ft_isdigit(c) == 1 && c != '0')
		mod->width = ft_atoi(num);
	return (s);
}

int		ft_isflagup(int c, int *chrc, va_list vl, t_mod *mod)
{
	int re;

	re = 0;
	if (c == 'C' && (re = 1) == 1)
	{
		mod->l = 1;
		ft_putchar(va_arg(vl, int));
		*chrc = *chrc + 1;
	}
	if (c == 'S' && (re = 1) == 1)
	{
		mod->l = 1;
		*chrc = *chrc + ft_printstring(vl, *mod);
	}
	if ((c == 'D' || c == 'O' || c == 'U') && (re = 1) == 1)
	{
		mod->l = 1;
		*chrc = *chrc + ft_pickconvert(vl, ft_tolower(c), *mod);
	}
	return (re);
}

int		ft_isflaglo(int c, int *chrc, va_list vl, t_mod mod)
{
	int re;

	re = 0;
	if (c == 's' && (re = 1) == 1)
		*chrc = *chrc + ft_printstring(vl, mod);
	if (c == 'c' && (re = 1) == 1)
		*chrc = *chrc + ft_printchar(vl, mod);
	if ((c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
				c == 'X' || c == 'u') && (re = 1) == 1)
		*chrc = *chrc + ft_pickconvert(vl, c, mod);
	if (c == 'p' && (re = 1) == 1)
	{
		mod.hash = 1;
		*chrc = *chrc + ft_unconvert((unsigned long)(va_arg(vl, void *)),
				16, 'x', &mod);
	}
	return (re);
}
