/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 10:01:49 by rojones           #+#    #+#             */
/*   Updated: 2016/07/28 15:04:40 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_rem_args(char **args)
{
	int		i;
	int		j;
	int		k;
	char	**re;

	i = 0;
	j = 0;
	k = 0;
	while (args[i] && ft_check_arg_op(args[i]) == 0)
		i++;
	k = i;
	if (args[i] == '\0')
		return (NULL);
	while (args[++i])
		j++;
	if (!(re = (char**)malloc(sizeof(char*) * (j + 1))))
	{
		ft_putstr("maloc failed");
		return (args);
	}
	i = -1;
	while (++i < j && args[++k])
		re[i] = strdup(args[k]);
	re[i] = NULL;
	return (re);
}
