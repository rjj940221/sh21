/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exc_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:16:14 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:45:54 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_exc_cd(char *path, char **env)
{
	char	*oldpwd;
	char	*pwd;
	char	*val;
	int		varloc;

	val = getcwd(NULL, 0);
	oldpwd = ft_pwd_var("OLDPWD", val);
	if (val)
		free(val);
	if (chdir(path) != 0)
	{
		ft_putstr("cd: chdir failed\n");
		return ;
	}
	val = getcwd(NULL, 0);
	pwd = ft_pwd_var("PWD", val);
	if (val)
		free(val);
	varloc = ft_check_env_var("OLDPWD", env);
	if (varloc != -1)
		ft_update_pwd_env(env, &oldpwd, varloc);
	varloc = ft_check_env_var("PWD", env);
	if (varloc != -1)
		ft_update_pwd_env(env, &pwd, varloc);
}
