/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_opwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:04:19 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:41:17 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_cd_opwd(char **env)
{
	int		varloc;
	char	**split;

	varloc = ft_check_env_var("OLDPWD", env);
	if (varloc == -1)
	{
		ft_putstr("cd: failed to get OLDPWD path\n");
		return ;
	}
	split = ft_strsplit(env[varloc], '=');
	if (split[1] == NULL)
	{
		ft_putstr("cd: failed to get OLDPWD path\n");
		return ;
	}
	ft_exc_cd(split[1], env);
	ft_free_str_arr(split);
	varloc = ft_check_env_var("PWD", env);
	if (varloc == -1)
		return ;
	split = ft_strsplit(env[varloc], '=');
	if (split[1] == NULL)
		return ;
	ft_printf("%s\n", split[1]);
	ft_free_str_arr(split);
}
