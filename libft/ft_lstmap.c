/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:10:41 by rojones           #+#    #+#             */
/*   Updated: 2016/05/14 16:48:12 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *re;
	t_list *temp1;
	t_list *temp2;

	if (!(re = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	re = (*f)(lst);
	lst = lst->next;
	temp1 = re;
	while (lst->next != NULL)
	{
		temp2 = (*f)(lst);
		temp1->next = temp2;
		temp1 = temp2;
		lst = lst->next;
	}
	return (re);
}
