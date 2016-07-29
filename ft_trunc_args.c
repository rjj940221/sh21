/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trunc_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:40:34 by rojones           #+#    #+#             */
/*   Updated: 2016/07/28 15:10:14 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char **ft_trunc_args(char **args)
{
	int i;
	int j;
	char	**re;

	i = 0;
	j = 0;
	while (args[i] && ft_check_arg_op(args[i]) == 0)
		i++;
	if (!(re = (char**)malloc(sizeof(char*) * (i + 1))))
	{
		ft_putstr("maloc failed");
		return (args);
	}
	
	while (j < i && args[j])
	{
		re[j] = strdup(args[j]);
		j++;
	}
	re[j] = NULL;
	return (re);
}
