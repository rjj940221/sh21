/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:51:52 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:08:03 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pad(char *s, t_mod *mod, int *chrc)
{
	mod->zero = mod->zero - mod->pos;
	mod->neg = mod->neg - mod->pos;
	while (mod->zero-- > 0 || mod->pre-- > 0)
	{
		mod->neg--;
		ft_putchar('0');
		*chrc = *chrc + 1;
	}
	ft_putstr(s);
	*chrc = *chrc + ft_strlen(s);
	while (mod->neg-- > 0)
	{
		ft_putchar(' ');
		*chrc = *chrc + 1;
	}
}

void	ft_padwide(wchar_t *s, t_mod *mod, int *chrc)
{
	mod->zero = mod->zero - mod->pos;
	mod->neg = mod->neg - mod->pos;
	while (mod->zero-- > 0 || mod->pre-- > 0)
	{
		mod->neg--;
		ft_putchar('0');
		*chrc = *chrc + 1;
	}
	ft_putstrwide(s);
	*chrc = *chrc + ft_strlenwide(s);
	while (mod->neg-- > 0)
	{
		ft_putchar(' ');
		*chrc = *chrc + 1;
	}
}

void	ft_padwidth(t_mod *mod, int *chrc, int c)
{
	mod->width = mod->width - mod->pos;
	if (mod->pre > 0)
		mod->width = mod->width - mod->pre;
	if ((c == 'x' || c == 'X') && mod->hash == 1)
		mod->width = mod->width - 2;
	if ((c == 'o' || c == 'O') && mod->hash == 1)
		mod->width = mod->width - 1;
	while (mod->width-- > 0)
	{
		mod->neg--;
		ft_putchar(' ');
		*chrc = *chrc + 1;
	}
}

void	ft_nummoders(t_mod *mod, int *chrc, int c)
{
	ft_posmod(mod, chrc, c);
	ft_spacemod(mod, chrc);
	ft_hashmod(mod, chrc, c);
}
