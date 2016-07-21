/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:28:36 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:40:25 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	*ft_build_env_var(char **split)
{
	char	*re;
	char	*temp;

	if (split[1] == NULL)
	{
		temp = ft_strjoin(split[0], "=");
		return (temp);
	}
	temp = ft_strjoin(split[0], "=");
	re = ft_strjoin(temp, split[1]);
	if (temp)
		free(temp);
	return (re);
}
