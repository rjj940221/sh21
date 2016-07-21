/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:41:54 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:47:29 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_get_comm(char *line, char **env)
{
	char	*comm;
	char	**split;

	split = ft_extract_args(line);
	comm = split[0];
	if (comm)
	{
		if (strcmp(comm, "echo") == 0)
			ft_echo(split, env);
		else if (strcmp(comm, "cd") == 0)
			ft_cd(split, env);
		else if (strcmp(comm, "setenv") == 0)
			env = ft_setenv(split, env);
		else if (strcmp(comm, "unsetenv") == 0)
			env = ft_unsetenv(split, env);
		else if (strcmp(comm, "env") == 0)
			ft_env(split, env);
		else if (ft_launch(split, env) == 0)
			ft_printf("command not found: %s\n", comm);
	}
	if (split)
		ft_free_str_arr(split);
	return (env);
}
