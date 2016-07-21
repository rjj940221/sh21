/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:28:05 by rojones           #+#    #+#             */
/*   Updated: 2016/05/30 10:18:07 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**re;
	int		numword;
	int		wordind;
	int		i;

	numword = ft_numwords(s, c);
	wordind = 0;
	i = 0;
	if (!(re = (char **)malloc(sizeof(char *) * (numword + 1))))
		return (NULL);
	while (wordind < numword)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		re[wordind] = ft_strsub(s, i, ft_wordlen(s, i, c) + 1);
		i = i + ft_wordlen(s, i, c) + 1;
		wordind++;
	}
	re[numword] = NULL;
	return (re);
}
