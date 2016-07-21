/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:28:53 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:42:41 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int		ft_check_env_var(char *arg, char **env)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(arg, "=");
	if (temp)
	{
		while (env[i])
		{
			if (ft_strstr(env[i], temp) == env[i])
			{
				free(temp);
				return (i);
			}
			i++;
		}
		free(temp);
	}
	return (-1);
}
