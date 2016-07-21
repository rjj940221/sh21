/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:46:36 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:50:40 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_replace_env_var(char **env, char *value, int i)
{
	char	**re;
	char	*temp;

	re = ft_cpyenv(env);
	if (!re || !value)
		return (env);
	temp = re[i];
	re[i] = strdup(value);
	free(value);
	if (temp)
		free(temp);
	return (re);
}

char	**ft_add_env_var(char **split, char **env)
{
	char	**re;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	if (!(re = (char **)malloc(sizeof(char *) * (i + 2))))
	{
		ft_putstr("add_env_var Memory allocation failed.\n");
		return (NULL);
	}
	while (env[j])
	{
		re[j] = strdup(env[j]);
		j++;
	}
	re[j++] = ft_build_env_var(split);
	re[j] = NULL;
	return (re);
}

static char	**ft_exc_setenv(char **split, char **env)
{
	char	*new_var;
	char	**re;
	int		i;

	if ((i = ft_check_env_var(split[0], env)) != -1)
	{
		new_var = ft_build_env_var(split);
		re = ft_replace_env_var(env, new_var, i);
	}
	else
		re = ft_add_env_var(split, env);
	if (re != NULL)
	{
		ft_free_str_arr(env);
		return (re);
	}
	return (env);
}

char	**ft_setenv(char **split, char **env)
{
	char	**new_split;
	char	**re;

	new_split = NULL;
	if (split[1] == NULL)
	{
		ft_putstr("incorect num args expecting FOO bar or FOO=bar.\n");
		return (env);
	}
	if (ft_strchr(split[1], '=') != NULL)
	{
		new_split = ft_strsplit(split[1], '=');
		re = ft_exc_setenv(new_split, env);
	}
	else
		re = ft_exc_setenv(&split[1], env);
	if (new_split != NULL)
		ft_free_str_arr(new_split);
	return (re);
}
