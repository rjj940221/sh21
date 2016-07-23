/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:41:54 by rojones           #+#    #+#             */
/*   Updated: 2016/07/23 13:49:57 by rojones          ###   ########.fr       */
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
		else if (ft_launch(split, env) == 0)
			ft_printf("command not found: %s\n", split[0]);
	}
	if (split)
		ft_free_str_arr(split);
	return (env);
}
