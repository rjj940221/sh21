/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 13:51:03 by rojones           #+#    #+#             */
/*   Updated: 2016/07/21 07:40:56 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static char	*ft_check_exe_path(char *path, char *name)
{
	char	*temp;
	char	*repath;

	temp = NULL;
	if (access(path, R_OK) == 0)
	{
		if (ft_check_dir(path, name) == 1)
		{
			if (path[ft_strlen(path) - 1] != '/')
				temp = ft_strjoin(path, "/");
			repath = ft_strjoin(temp, name);
			if (temp)
				free(temp);
			if (access(repath, X_OK) == 0)
				return (repath);
			if (repath)
				free(repath);
		}
	}
	return (NULL);
}

static char	*ft_check_abs_path(char *path)
{
	if (access(path, R_OK) == 0)
	{
		if (access(path, X_OK) == 0)
			return (ft_strdup(path));
	}
	return (NULL);
}

char		*ft_search_path(char **args, char **env)
{
	char	**spath;
	char	*val;
	char	*path;
	int		i;

	val = ft_get_env_var(env, ft_check_env_var("PATH", env));
	path = ft_check_abs_path(args[0]);
	if (val != NULL)
	{
		spath = ft_strsplit(val, ':');
		i = 0;
		while (spath[i] && path == NULL)
		{
			path = ft_check_exe_path(spath[i], args[0]);
			i++;
		}
		ft_free_str_arr(spath);
	}
	if (val)
		free(val);
	return (path);
}
