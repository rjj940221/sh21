/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 16:55:17 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:48:06 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	*ft_get_env_var(char **env, int ind)
{
	char	*re;
	char	**split;

	re = NULL;
	if (ind > -1)
	{
		split = ft_strsplit(env[ind], '=');
		re = ft_strdup(split[1]);
		ft_free_str_arr(split);
	}
	return (re);
}
