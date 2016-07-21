/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:49:16 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:51:04 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_rm_env_var(char **env, int rm_ind)
{
	int		i;
	int		off;
	char	**re;

	i = 0;
	off = 0;
	while (env[i])
		i++;
	if (!(re = (char **)malloc(sizeof(char*) * i)))
	{
		ft_putstr("malloc error");
		return (NULL);
	}
	i = 0;
	while (env[i])
	{
		if (i == rm_ind)
			off = -1;
		else
			re[i + off] = strdup(env[i]);
		i++;
	}
	re[i + off] = NULL;
	return (re);
}

char	**ft_unsetenv(char **split, char **env)
{
	char	**re;
	int		rm;

	if (split[1] == NULL)
	{
		ft_putstr("no args apssed");
		return (NULL);
	}
	rm = ft_check_env_var(split[1], env);
	re = ft_rm_env_var(env, rm);
	if (re == NULL)
		return (env);
	ft_free_str_arr(env);
	return (re);
}
