/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:31:28 by rojones           #+#    #+#             */
/*   Updated: 2016/07/23 17:45:29 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static char	*ft_malloc(int len)
{
	char	*re;

	if (!(re = (char*)malloc(sizeof(char) * (len + 1))))
	{
		ft_putstr("extract arg malloc error");
		return (NULL);
	}
	return (re);
}

char		*ft_extract_arg(int len, int start, int *end, char *line)
{
	int		i;
	int		qut;
	int		oldst;
	char	*re;

	i = 0;
	qut = 0;
	if (!(re = ft_malloc(len)))
		return (NULL);
	while (i < len && start < *end)
	{
		oldst = start;
		ft_check_arg_case_len(line, &qut, &start);
		if (start == oldst)
		{
			re[i] = line[start];
			i++;
			start++;
		}
	}
	re[i] = '\0';
	ft_skip_space(line, end);
	return (re);
}
