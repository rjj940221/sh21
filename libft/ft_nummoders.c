/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nummoders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:18:29 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:07:30 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_posmod(t_mod *mod, int *chrc, int c)
{
	if (mod->pos == 1 && (c != 'x' || c != 'X' || c != 'u' || c != 'U'))
	{
		ft_putchar('+');
		*chrc = *chrc + 1;
	}
}

void	ft_spacemod(t_mod *mod, int *chrc)
{
	if (mod->space == 1)
	{
		ft_putchar(' ');
		*chrc = *chrc + 1;
	}
}

void	ft_hashmod(t_mod *mod, int *chrc, int c)
{
	if (mod->hash == 1 && (c == 'x' || c == 'X'))
	{
		if (c == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		*chrc = *chrc + 2;
		mod->zero = mod->zero - 2;
	}
	if (mod->hash == 1 && c == 'o')
	{
		*chrc = *chrc + 1;
		ft_putchar('0');
		mod->zero--;
	}
}
