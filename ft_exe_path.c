/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 10:02:46 by rojones           #+#    #+#             */
/*   Updated: 2016/07/25 10:11:47 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_exe_path(char **args, char **env)
{
	char    *path;

	if ((path = ft_search_path(args, env)) == NULL)
		return (0);
	execve(path, args, env);
	if (path)
		free(path);
	return (1);
}
