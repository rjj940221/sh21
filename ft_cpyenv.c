/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:40:46 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:43:20 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_cpyenv(char **env)
{
	char	**re;
	int		i;
	int		j;

	i = 0;
	j = 0;
	re = NULL;
	while (env[i])
		i++;
	if (!(re = (char **)malloc(sizeof(char *) * (i + 1))))
	{
		ft_putstr("copy_env Memory allocation failed.");
		return (NULL);
	}
	while (env[j])
	{
		re[j] = ft_strdup(env[j]);
		j++;
	}
	re[j] = NULL;
	return (re);
}
