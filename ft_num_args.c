/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:26:27 by rojones           #+#    #+#             */
/*   Updated: 2016/07/29 17:01:21 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_inc_word(char *line, int *i, int *qut)
{
	int	end;
	int	re;

	re = 0;
	end = 0;
	while (line[*i] && end == 0)
	{
		re = 1;
		ft_check_arg_case_len(line, qut, i);
		if (line[*i] == '\0' || (ft_isspace(line[*i]) == 1 && *qut == 0) ||
				(ft_isop(line[*i]) == 1 && *qut == 0))
			end = 1;
		else
			*i = *i + 1;
	}
	return (re);
}

static int	ft_get_qut(char *line)
{
	char	*line2;
	char	*temp;
	int		re;

	temp = NULL;
	line2 = NULL;
	ft_putstr("quote>");
	if (get_next_line(0, &line2) > 0)
	{
		temp = ft_strjoin(line, line2);
	}
	re = ft_num_args(temp);
	if (temp)
		free(temp);
	if (line2)
		free(line2);
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
		if (ft_isop(line[i]) == 1 && i > 0 && ft_isspace(line[i - 1]) == 0)
		{
			printf("%s\n", &line[i]);
			puts ("increacing num words");
			re++;
		}
		while (line[i] != '\0' && ft_isop(line[i]) == 1)
			i++;
	}
	if (qut == 1)
		re = ft_get_qut(line);
	return (re);
}
