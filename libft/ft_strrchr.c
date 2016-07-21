/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:06:44 by rojones           #+#    #+#             */
/*   Updated: 2016/05/11 18:05:38 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	test;
	int		i;

	test = c;
	i = (int)ft_strlen(str);
	while (i-- >= 0)
	{
		if (str[i] == test)
			return ((char *)(&str[i]));
	}
	return (NULL);
}
