/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:59:10 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:08:54 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printstring(va_list vl, t_mod mod)
{
	int		re;
	char	*s;

	re = 0;
	if (mod.pos == 1)
		mod.pos = 0;
	if (mod.l == 1)
		return (ft_printwstring(vl, mod));
	s = va_arg(vl, char *);
	ft_stringformat(s, &mod);
	ft_padwidth(&mod, &re, 's');
	ft_pad(s, &mod, &re);
	return (re);
}

int		ft_printwstring(va_list vl, t_mod mod)
{
	int		re;
	wchar_t	*s;

	re = 0;
	s = va_arg(vl, wchar_t *);
	ft_stringformatwide(s, &mod);
	ft_padwidth(&mod, &re, 's');
	ft_padwide(s, &mod, &re);
	return (re);
}

void	ft_stringformat(char *s, t_mod *mod)
{
	int strlen;

	strlen = ft_strlen(s);
	mod->width = mod->width - strlen;
	mod->neg = mod->neg - strlen;
	mod->zero = mod->zero - strlen;
}

void	ft_stringformatwide(wchar_t *s, t_mod *mod)
{
	int strlen;

	strlen = ft_strlenwide(s);
	mod->width = mod->width - strlen;
	mod->neg = mod->neg - strlen;
	mod->zero = mod->zero - strlen;
}
