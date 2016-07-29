/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_arg_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 08:39:11 by rojones           #+#    #+#             */
/*   Updated: 2016/07/28 15:07:49 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char ***ft_split_arg_op(char **args)
{
	char 	***re;
	char	**rem;
	char	**rem2;
	int		i;
	int 	j;

	i = -1;
	j = 0;
	while (args[++i])
		if (ft_check_arg_op(args[i]))
			j++;
	j++;
	if (!(re = (char***)malloc(sizeof(char**) * (j + 1))))
		return (NULL);
	i = -1;
	rem = ft_cpyenv(args);
	while (++i < j)
	{
		if (rem)
		{
			re[i] = ft_trunc_args(rem);
			rem2 = ft_cpyenv(rem);

			ft_free_str_arr(rem);
			rem = ft_rem_args(rem2);
			if (rem2)
				ft_free_str_arr(rem2);
		}
	}
	re[i] = NULL;
	return (re);
}
