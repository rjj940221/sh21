/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh21.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 11:50:00 by rojones           #+#    #+#             */
/*   Updated: 2016/07/25 16:56:08 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_oflag(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-o") == 0)
			return (1);
		i++;
	}
	return (-1);
}

static char	*ft_get_prompt(char **env)
{
	char	*h;
	char	*p;
	char	*t;
	int		check;

	h = NULL;
	p = NULL;
	t = NULL;
	check = ft_check_env_var("HOME", env);
	if (check != -1)
		h = ft_get_env_var(env, check);
	if (check != -1)
		check = ft_check_env_var("PWD", env);
	if (check != -1)
		p = ft_get_env_var(env, check);
	if (p && h)
	{
		if (ft_strstr(p, h) == p)
			t = ft_strdup(&p[ft_strlen(h)]);
	}
	if (p)
		free(p);
	if (h)
		free(h);
	return (t);
}

static void	ft_prompt(int oflag, char **env)
{
	char	*p;

	p = NULL;
	if (oflag == 1)
	{
		p = ft_get_prompt(env);
		if (p != NULL)
			ft_printf("%s> ", p);
	}
	if (oflag == -1 || p == NULL)
		write(1, "$> ", 3);
	if (p)
		free(p);
}

int			main(int ac, char **av)
{
	char		*line;
	char		**env;
	extern char	**environ;
	int			oflag;

	env = ft_cpyenv(environ);
	oflag = ft_oflag(ac, av);
	while (1)
	{
		ft_prompt(oflag, env);
		get_next_line(0, &line);
		line = ft_check_qut(line);
		if (line[0] != '\0')
		{   
			env = ft_split_input(line, env);
		}   
		if (line)
			free(line);
	}
}

/*int	main()
  {
  char        *line;
  char		**split;

  get_next_line(0, &line);
  line = ft_check_qut(line);
  if (line[0] != '\0')
  {
  split = ft_extract_args(line);
  while (*split)
  {
  puts(*split);
  split++;
  }
  }
  }*/
