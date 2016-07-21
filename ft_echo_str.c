/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 07:42:58 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:45:11 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_echo_exit(char *str, int i)
{
	if (str[i + 1] == 'c')
		return (1);
	else
		return (0);
}

static char	*ft_malloc_echo(char *str)
{
	char	*pr;
	int		strlen;

	strlen = ft_strlen(str);
	if (!(pr = (char*)malloc(sizeof(char) * (strlen + 1))))
		return (NULL);
	return (pr);
}

static void	ft_print_echo(char **str)
{
	ft_putstr(*str);
	free(*str);
}

int			ft_echo_str(char *str)
{
	char	*pr;
	int		i;
	int		j;
	int		re;

	re = 0;
	if (!(pr = ft_malloc_echo(str)))
		return (1);
	i = 0;
	j = 0;
	while (str[i] && re == 0)
	{
		if (str[i] == '\\')
		{
			re = ft_echo_exit(str, i);
			pr[j] = ft_echo_case(str, &i);
		}
		else
			pr[j] = str[i];
		i++;
		j++;
	}
	pr[j] = '\0';
	ft_print_echo(&pr);
	return (re);
}
