/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:30:38 by rojones           #+#    #+#             */
/*   Updated: 2016/07/21 11:16:13 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_extract_args(char *line)
{
	char	**re;
	int		i;
	int		mv;
	int		numargs;
	int		argindex;

	numargs = ft_num_args(line);
	argindex = 0;
	if (!(re = (char **)malloc(sizeof(char*) * (numargs + 1))))
	{
		ft_putstr("extract arg malloc failer");
		return (NULL);
	}
	i = 0;
	while (ft_isspace(line[i]) == 1)
		i++;
	while (argindex < numargs)
	{
		mv = i;
		re[argindex] = ft_extract_arg(ft_arglen(line, &mv), i, &mv, line);
		argindex++;
		i = mv;
	}
	re[argindex] = NULL;
	return (re);
}
