/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:03:31 by rojones           #+#    #+#             */
/*   Updated: 2016/07/19 13:34:34 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_str_arr(char **arr)
{
	char	*temp;
	int		i;

	if (arr)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			temp = arr[i];
			if (temp)
				free(temp);
			arr[i] = NULL;
			i++;
		}
		if (arr)
			free(arr);
	}
}
