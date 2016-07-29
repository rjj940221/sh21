/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:08:05 by rojones           #+#    #+#             */
/*   Updated: 2016/07/28 17:19:03 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

/*
** for ever out put run all input redir and pipe.
*/

static char	**ft_get_redir_in(char **args)
{
	return (args);
}

static char **ft_get_redir_out(char **args)
{
	return (args);
}

int ft_next_op(char **args)
{
	int	i;
	char	**in;
	char	**out;

	i = 0;
	in = ft_get_redir_in(args);
	out = ft_get_redir_out(args);
	while (args[i])
	{
		if (ft_strcmp(">", args[i]) == 0)
		   return (1);
		else if (ft_strcmp(">>", args[i]) == 0)
			return (2);
		else if (ft_strcmp("<", args[i]) == 0)
		   return (3);
		else if (ft_strcmp("<<", args[i]) == 0)
			return (4);
		else if (ft_strcmp("|", args[i]) == 0)
			return (5);
		i++;
	}
	return (0);
}
