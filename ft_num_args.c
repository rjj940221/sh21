/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:26:27 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:48:42 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_inc_word(char *line, int *i, int *qut)
{
	int	end;
	int	re;

	re = 0;
	end = 0;
	while (line[*i] && end == 0)
	{
		re = 1;
		ft_check_arg_case_len(line, qut, i);
		if (line[*i] == '\0' || (ft_isspace(line[*i]) == 1 && *qut == 0))
			end = 1;
		else
			*i = *i + 1;
	}
	return (re);
}

int	ft_num_args(char *line)
{
	int		re;
	int		qut;
	int		i;

	i = 0;
	qut = 0;
	re = 0;
	while (line[i] != '\0')
	{
		ft_skip_space(line, &i);
		re += ft_inc_word(line, &i, &qut);
	}
	return (re);
}
