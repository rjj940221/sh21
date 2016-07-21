/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 14:44:26 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:42:00 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_check_dir(char *path, char *name)
{
	DIR				*dir;
	struct dirent	*dre;
	int				namelen;

	if (!(dir = opendir(path)))
	{
		ft_printf("failed to search path directory %s", path);
		return (0);
	}
	namelen = strlen(name);
	while ((dre = readdir(dir)) != NULL)
	{
		if (dre->d_namlen == namelen && strcmp(dre->d_name, name) == 0)
		{
			(void)closedir(dir);
			return (1);
		}
	}
	(void)closedir(dir);
	return (0);
}
