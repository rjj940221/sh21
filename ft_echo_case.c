/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 09:15:56 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:44:11 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_echo_case_cmd(char *str, int *i, char *re)
{
	char	c;
	int		check;

	c = str[*i + 1];
	check = 0;
	if (c == '\\' || c == 'a' || c == 'b' || c == 'c' || c == 'e' || c == '"')
		check = 1;
	if (c == '\\')
		*re = '\\';
	else if (c == 'a')
		*re = '\a';
	else if (c == 'b')
		*re = '\b';
	else if (c == 'c')
		*re = '\0';
	else if (c == 'e')
		*re = 27;
	else if (c == '"')
		*re = '"';
	if (check == 1)
		*i = *i + 1;
	return (check);
}

static int	ft_echo_case_tab(char *str, int *i, char *re)
{
	char	c;
	int		check;

	c = str[*i + 1];
	check = 0;
	if (c == 'n' || c == 'r' || c == 't' || c == 'v')
		check = 1;
	if (c == 'n')
		*re = '\n';
	else if (c == 'r')
		*re = '\r';
	else if (c == 't')
		*re = '\t';
	else if (c == 'v')
		*re = '\v';
	if (check == 1)
		*i = *i + 1;
	return (check);
}

static int	ft_echo_case_nbr_oct(char *str, int *i, char *re)
{
	int		checknum;
	char	*num;

	if (str[*i + 1] == '0')
	{
		num = ft_strsub(str, (unsigned int)(*i + 2), 3);
		checknum = ft_atoi_base(num, 8);
		if (ft_isprint(checknum) != 0)
		{
			*i = *i + 5;
			*re = checknum;
			free(num);
		}
		else
		{
			*i = *i + 2;
			*re = str[*i];
		}
		return (1);
	}
	else
		return (0);
}

static int	ft_echo_case_nbr_hex(char *str, int *i, char *re)
{
	int		checknum;
	char	*num;

	if (str[*i + 1] == 'x')
	{
		num = ft_strsub(str, (unsigned int)(*i + 2), 2);
		checknum = ft_atoi_base(num, 16);
		if (ft_isprint(checknum) != 0)
		{
			*i = *i + 4;
			*re = checknum;
			free(num);
		}
		else
		{
			*i = *i + 2;
			*re = str[*i];
		}
		return (1);
	}
	else
		return (0);
}

char		ft_echo_case(char *str, int *i)
{
	char	re;
	int		check;

	check = ft_echo_case_cmd(str, i, &re);
	if (check == 0)
		check = ft_echo_case_tab(str, i, &re);
	if (check == 0)
		check = ft_echo_case_nbr_oct(str, i, &re);
	if (check == 0)
		check = ft_echo_case_nbr_hex(str, i, &re);
	if (check == 0)
		re = '\\';
	return (re);
}
