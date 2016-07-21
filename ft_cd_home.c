/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:03:08 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:41:05 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_cd_home(char **env)
{
	int		varloc;
	char	**split;

	varloc = ft_check_env_var("HOME", env);
	if (varloc == -1)
	{
		ft_putstr("cd: failed to get HOME path\n");
		return ;
	}
	split = ft_strsplit(env[varloc], '=');
	if (split[1] == NULL)
	{
		ft_putstr("cd: failed to get HOME path\n");
		return ;
	}
	ft_exc_cd(split[1], env);
	ft_free_str_arr(split);
}
