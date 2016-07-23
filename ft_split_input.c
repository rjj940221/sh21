/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 12:49:21 by rojones           #+#    #+#             */
/*   Updated: 2016/07/22 13:57:57 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static char	*ft_strchar(char *str, char c)
{
	int i;
	int	qut;

	i = 0;
	qut = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '"' && i > 0 && str[i - 1] != '\\')
			qut = (qut == 0) ? 1 : 0;
		if (str[i] == c && qut == 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split_input(char *line, char **env)
{
	char	*col;
	char	*mv;
	char	*temp;

	mv = line;
	while ((col = ft_strchar(mv, ';')) != NULL)
	{
		temp = ft_strsub(mv, 0 , (int)(col - mv));
		if (temp)
		{
			env = ft_get_comm(temp, env);
			free(temp);
		}
		mv = col + 1;
	}
	env = ft_get_comm(mv, env);
	return (env);
}
