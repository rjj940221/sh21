/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 15:13:57 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:07:11 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_addmod(char c, t_mod *mod)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		ft_addlenmod(c, mod);
	else
		ft_formmod(c, mod);
}

void	ft_addlenmod(int c, t_mod *mod)
{
	if (c == 'h' && mod->h == 1)
		mod->hh = 1;
	else if (c == 'h')
		mod->h = 1;
	else if (c == 'l')
		mod->l = 1;
	else if (c == 'l' && mod->l == 1)
		mod->ll = 1;
	else if (c == 'j')
		mod->j = 1;
	else if (c == 'z')
		mod->z = 1;
}

void	ft_formmod(char c, t_mod *mod)
{
	if (c == '#')
		mod->hash = 1;
	else if (c == '-')
	{
		mod->zero = 0;
		mod->neg = 1;
	}
	else if (c == '+')
	{
		mod->space = 0;
		mod->pos = 1;
	}
	else if (c == ' ' && mod->pos == 0)
		mod->space = 1;
}

void	ft_initmod(t_mod *mod)
{
	mod->hash = 0;
	mod->zero = -1;
	mod->pre = -1;
	mod->width = -1;
	mod->neg = 0;
	mod->pos = 0;
	mod->space = 0;
	mod->hh = 0;
	mod->h = 0;
	mod->l = 0;
	mod->ll = 0;
	mod->j = 0;
	mod->z = 0;
}
