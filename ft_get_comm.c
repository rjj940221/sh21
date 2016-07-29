/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:41:54 by rojones           #+#    #+#             */
/*   Updated: 2016/07/29 15:42:05 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char    **ft_get_comm(char **split, char **env)
{
	char	*path;

	path = NULL;
	if (split[0])
	{
		if (strcmp(split[0], "exit") == 0)
			ft_exit(split, env);
		else if (strcmp(split[0], "echo") == 0)
			ft_echo(split, env);
		else if (strcmp(split[0], "cd") == 0)
			ft_cd(split, env);
		else if (strcmp(split[0], "setenv") == 0)
			env = ft_setenv(split, env);
		else if (strcmp(split[0], "unsetenv") == 0)
			env = ft_unsetenv(split, env);
		else if (strcmp(split[0], "env") == 0)
			ft_env(split, env);
		else if ((path = ft_search_path(split, env)) != NULL)
			execve(path, split, env);
		else
			ft_printf("command not found: %s\n", split[0]);
		if (path)
			free(path);
	}
	return (env);
}
