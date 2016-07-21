/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:44:03 by rojones           #+#    #+#             */
/*   Updated: 2016/05/13 09:57:43 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *const s1, const char *const s2)
{
	char	*loop;
	int		i;

	i = 0;
	loop = (s1 + ft_strlen(s1));
	while (s2[i] != '\0')
		*loop++ = s2[i++];
	*loop = '\0';
	return (s1);
}
