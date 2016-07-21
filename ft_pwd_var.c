/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:20:08 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:50:09 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	*ft_pwd_var(char *pwd, char *value)
{
	char	*re;
	char	*temp;

	temp = ft_strjoin(pwd, "=");
	re = ft_strjoin(temp, value);
	if (temp)
		free(temp);
	return (re);
}
