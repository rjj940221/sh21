/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 13:36:10 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:48:21 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_launch(char **args, char **env)
{
	pid_t	pid;
	char	*path;
	int		status;

	if ((path = ft_search_path(args, env)) == NULL)
		return (0);
	pid = fork();
	if (pid > 0)
		wait(&status);
	if (pid == 0)
		execve(path, args, env);
	if (path)
		free(path);
	return (1);
}
