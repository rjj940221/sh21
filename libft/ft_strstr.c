/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:15:01 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:03:12 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	ind_big;
	int	ind_l;

	ind_big = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[ind_big] != '\0')
	{
		ind_l = 0;
		while (big[ind_big] == little[ind_l] && little[ind_l] != '\0')
		{
			if (little[ind_l + 1] == '\0')
				return ((char *)&big[ind_big - ind_l]);
			ind_big++;
			ind_l++;
		}
		ind_big = ind_big - ind_l;
		ind_big++;
	}
	return (NULL);
}
