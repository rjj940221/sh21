/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numwod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:20:51 by rojones           #+#    #+#             */
/*   Updated: 2016/06/03 09:02:53 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numwords(char const *s, char c)
{
	int numword;
	int i;
 
	i = 0;
	numword = 0;
	while (s[i] != '\0')
	{
		if (ft_newword(s, i, c) == 1)
			numword++;
		i++;
	}
	return (numword);
}
