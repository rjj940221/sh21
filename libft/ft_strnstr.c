/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 09:44:22 by rojones           #+#    #+#             */
/*   Updated: 2016/05/12 09:54:22 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i_l;
	int	i_b;

	i_b = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i_b < (int)len && big[i_b] != '\0')
	{
		i_l = 0;
		while (big[i_b] == little[i_l] && i_b < (int)len && big[i_b] != '\0')
		{
			if (little[i_l + 1] == '\0')
				return ((char *)&big[i_b - i_l]);
			i_b++;
			i_l++;
		}
		i_b = i_b - i_l;
		i_b++;
	}
	return (NULL);
}
