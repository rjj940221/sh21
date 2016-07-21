/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:58:41 by rojones           #+#    #+#             */
/*   Updated: 2016/05/14 12:06:00 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite(char s)
{
	if (s == ' ' || s == '\t' || s == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*re;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = ft_strlen(s) - 1;
	while (ft_iswhite(s[i]) == 1)
		i++;
	while (ft_iswhite(s[length]) == 1)
		length--;
	if (!(re = (char *)malloc(sizeof(char) * ((length - i) + 1))))
		return (NULL);
	while (i <= length)
		re[j++] = s[i++];
	re[j] = '\0';
	return (re);
}
