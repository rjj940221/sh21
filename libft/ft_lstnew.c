/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 14:08:20 by rojones           #+#    #+#             */
/*   Updated: 2016/07/18 16:01:01 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *re;

	if (!(re = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		re->content = NULL;
		re->content_size = 0;
	}
	else
	{
		if (!(re->content = malloc(content_size)))
			return (NULL);
		re->content_size = content_size;
		memcpy(re->content, content, content_size);
	}
	re->next = NULL;
	return (re);
}
