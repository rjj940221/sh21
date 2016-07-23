/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_qut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:42:59 by rojones           #+#    #+#             */
/*   Updated: 2016/07/23 16:01:14 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static char	*ft_get_qut(char *line)
{
	char	*line2;
	char	*temp;

	temp = NULL;
	line2 = NULL;
	ft_putstr("quote>");
	if (get_next_line(0, &line2) > 0)
	{
		temp = ft_strjoin(line, line2);
	}
	if (line)
		free(line);
	if (line2)
		free(line2);
	return (temp);
}

char	*ft_check_qut(char *line)
{
	int		i;
	int		qut;
	char	*re;

	qut = 0;
	i = 0;
	re = line;
	while (line[i])
	{
		if (i == 0 && line[i] == '"')
			qut = 1;
		if (i > 0 && line[i] == '"' && line[i - 1] != '\\')
			qut = (qut == 0) ? 1 : 0;
		i++;
	}
	if (qut)
	{
		re = ft_get_qut(line);
		re = ft_check_qut(re);
	}
	return (re);
}
