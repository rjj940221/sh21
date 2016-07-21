/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:13:08 by rojones           #+#    #+#             */
/*   Updated: 2016/06/03 08:38:42 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int  ft_newword(const char *s, unsigned int i, char del)
{
	if (i == 0 && s[i] == del)
		return (0);
	if (i == 0 && s[i] != del)
		return (1);
	if (s[i - 1] == del && s[i] != del)
		return (1);
	return (0);
}
