/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_case_len.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 14:20:17 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:41:43 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	ft_check_arg_case_len_i(char *line, int *qut, int *i)
{
	if (line[*i] == '\\' && line[*i - 1] != '\\' && *qut == 0)
		*i = *i + 1;
	else if (line[*i] == '"' && *qut == 0 && line[*i - 1] != '\\')
	{
		*i = *i + 1;
		*qut = 1;
	}
	else if (line[*i] == '"' && line[*i - 1] != '\\')
	{
		*i = *i + 1;
		*qut = 0;
	}
}

static void	ft_check_arg_case_len_z(char *line, int *qut, int *i)
{
	if (line[*i] == '\\')
		*i = *i + 1;
	else if (line[*i] == '"' && *qut == 0)
	{
		*i = *i + 1;
		*qut = 1;
	}
	else if (line[*i] == '"')
	{
		*i = *i + 1;
		*qut = 0;
	}
}

void		ft_check_arg_case_len(char *line, int *qut, int *i)
{
	if (*i > 0)
		ft_check_arg_case_len_i(line, qut, i);
	else
		ft_check_arg_case_len_z(line, qut, i);
}
