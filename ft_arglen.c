/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arglen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 14:21:13 by rojones           #+#    #+#             */
/*   Updated: 2016/07/25 13:32:01 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_arglen(char *s, int *start)
{
	int i;
	int	qut;

	i = 0;
	qut = 0;
	if (ft_isop(s[*start]) == 1)
	{
		while (s[*start] != '\0' && ft_isop(s[*start]) == 1)
		{
			i++;
			*start = *start + 1;
		}
	}
	else
	{
		while (s[*start] != '\0')
		{
			ft_check_arg_case_len(s, &qut, start);
			if ((ft_isspace(s[*start]) == 1 || ft_isop(s[*start]) == 1) && qut == 0)
				return (i);
			i++;
			*start = *start + 1;
		}
	}
	return (i);
}
