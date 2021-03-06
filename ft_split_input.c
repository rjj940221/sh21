/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 12:49:21 by rojones           #+#    #+#             */
/*   Updated: 2016/07/29 12:10:16 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_split_input(char *line, char **env)
{
	char	*col;
	char	*mv;
	char	*temp;

	mv = line;
	while ((col = ft_str_qut_char(mv, ';')) != NULL)
	{
		temp = ft_strsub(mv, 0 , (int)(col - mv));
		if (temp)
		{
			env = ft_launch(temp, env);
			free(temp);
		}
		mv = col + 1;
	}
	env = ft_launch(mv, env);
	return (env);
}
