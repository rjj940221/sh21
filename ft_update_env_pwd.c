/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env_pwd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:23:39 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:51:16 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_update_pwd_env(char **env, char **value, int i)
{
	char	*temp;

	if (!(*value))
		return ;
	temp = env[i];
	env[i] = ft_strdup(*value);
	if (temp)
		free(temp);
	free(*value);
}
