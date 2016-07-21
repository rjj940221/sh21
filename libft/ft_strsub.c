/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:17:21 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 07:47:57 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*re;
	int		i;

	i = 0;
	re = ft_strnew(len + 1);
	if (re == NULL)
		return (NULL);
	len = len + start;
	if (start < ft_strlen(s))
	{
		while (s[start] != '\0' && start < len)
		{
			re[i] = s[start];
			start++;
			i++;
		}
	}
	re[i] = '\0';
	return (re);
}
