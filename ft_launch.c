/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 13:36:10 by rojones           #+#    #+#             */
/*   Updated: 2016/07/29 17:33:44 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_launch(char *line, char **env)
{
	pid_t	pid;
	int		status;
	char	**args;
	char	*redir;

	redir = ft_get_redir(line);
	args = ft_extract_args(line);
	if (args && args[0])
	{
		if (ft_strcmp(args[0], "exit") == 0)
			ft_exit(args, env);
		else if (strcmp(args[0], "cd") == 0)
			ft_cd(args, env);
		else if (strcmp(args[0], "setenv") == 0)
		    env = ft_setenv(args, env);
		else if (strcmp(args[0], "unsetenv") == 0)
		    env = ft_unsetenv(args, env);
		else
		{
			pid = fork();
			if (pid > 0)
				wait(&status);
			if (pid == 0)
			{
				env = ft_op_order(args, env);
				exit(0);
			}
			ft_free_str_arr(args);
		}
	}
	return (env);
}
