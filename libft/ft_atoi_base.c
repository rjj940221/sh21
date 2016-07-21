/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 09:46:23 by rojones           #+#    #+#             */
/*   Updated: 2016/07/08 11:58:07 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_prep(const char *str, int *i, int *signe)
{
	while (ft_isspace(str[*i]) == 1)
		*i = *i + 1;
	if (str[*i] == '-')
	{
		*signe = -1;
		*i = *i + 1;
	}
	if (str[*i] == '+')
		*i = *i + 1;
}

int			ft_atoi_base(const char *str, int base)
{
	int	signe;
	int	re;
	int	i;
	int	num;
	int	p;

	i = 0;
	p = ft_strlen(str) - 1;
	re = 0;
	signe = 1;
	ft_prep(str, &i, &signe);
	while (str[i] != '\0' && (num = ft_ishex(str[i])) != -1)
	{
		re = re + (ft_power(base, p) * num);
		i++;
		p--;
	}
	if (num == -1)
		return (-1);
	return (re * signe);
}
