/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 17:36:08 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:44:55 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_print_prepend(char *arg)
{
	char	*pr;
	char	*ptr;

	ptr = ft_strstr(arg, "$");
	pr = ft_strsub(arg, 0, (int)(ptr - arg));
	ft_putstr(pr);
	if (pr)
		free(pr);
	return (1);
}

int			ft_echo_print_env_var(char **env, char *arg)
{
	char	*pr;
	int		ind;

	if (arg[1] == '\0' || arg[1] == '\\')
	{
		ft_putstr("$");
		return (1);
	}
	else
	{
		ind = ft_check_env_var(&arg[1], env);
		if (ind == -1)
			return (0);
		pr = ft_get_env_var(env, ind);
		ft_putstr(pr);
		free(pr);
	}
	return (1);
}

int			ft_echo_env_var(char **env, char *arg)
{
	int		re;
	char	*ptr1;
	char	*ptr2;
	char	*var;

	re = 0;
	if (arg[0] != '$')
		re += ft_print_prepend(arg);
	ptr1 = ft_strstr(arg, "$");
	while ((ptr2 = ft_strstr(&ptr1[1], "$")) != NULL)
	{
		var = ft_strsub(ptr1, 0, (ptr2 - ptr1));
		if (var)
		{
			re += ft_echo_print_env_var(env, var);
			free(var);
		}
		ptr1 = ptr2;
	}
	re += ft_echo_print_env_var(env, ptr1);
	return (re);
}
