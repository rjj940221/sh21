/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 15:06:47 by rojones           #+#    #+#             */
/*   Updated: 2016/05/14 16:47:39 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = *alst;
	if (temp->next != NULL)
		ft_lstdel(&(temp->next), del);
	(*del)(temp->content, temp->content_size);
	free(temp->content);
	temp->next = NULL;
	free(*alst);
	alst = NULL;
}
