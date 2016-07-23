/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_qut_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:22:14 by rojones           #+#    #+#             */
/*   Updated: 2016/07/23 15:53:39 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	*ft_str_qut_char(char *str, char c)
{
	int i;
	int	qut;

	i = 0;
	qut = 0;
	while(str[i] != '\0')
	{
		 if (i == 0 && str[i] == '"')
			qut = 1;
		if (str[i] == '"' && i > 0 && str[i - 1] != '\\')
			qut = (qut == 0) ? 1 : 0;
		if (str[i] == c && qut == 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
