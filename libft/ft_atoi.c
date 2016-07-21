/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:23:31 by rojones           #+#    #+#             */
/*   Updated: 2016/06/07 17:03:35 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int	signe;
	int	re;
	int	i;

	i = 0;
	re = 0;
	signe = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		re = (re * 10) + (str[i] - '0');
		i++;
	}
	return (re * signe);
}
