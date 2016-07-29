/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:10:04 by rojones           #+#    #+#             */
/*   Updated: 2016/07/29 15:41:48 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	ft_redir_out(char **args, int op)
{
	int     fd;
	int     s;

	s = 0;
	while (ft_check_arg_op(args[s]) == 0)
		s++;
	s++;
	if (op == 1)
		fd = open(args[s], O_RDWR | O_TRUNC | O_CREAT, 0777);
	else
		fd = open(args[s], O_RDWR | O_APPEND | O_CREAT, 0777);
	if (fd == -1)
	{
		ft_putstr("failed to open file");
		return ;
	}
	dup2(fd, 1);
	close(fd);
	return ;
}

static void	ft_redir_in(char **args, int op)
{
	int     fd;
	int     s;

	s = 0;
	while (ft_check_arg_op(args[s]) == 0)
		s++;
	s++;
	fd = -1;
	if (op == 3)
		fd = open(args[s], O_RDONLY | O_CREAT, 0777);
	if (fd == -1)
	{
		ft_putstr("failed to open file");
		return ;
	}
	dup2(fd, 0);
	close(fd);
	return ;
}

static char	**ft_pipe(char **args, char **env)
{
	int   p[2];
	pid_t pid;
	int   fd_in = 0;
	int		i;
	char	***cmd;

	i = 0;
	cmd = ft_split_arg_op(args);
	while (cmd[i] != NULL)
	{
		pipe(p);
		if ((pid = fork()) == -1)
			exit(EXIT_FAILURE);
		else if (pid == 0)
		{
			dup2(fd_in, 0); //change the input according to the old one 
			if ((cmd[i + 1]) != NULL)
				dup2(p[1], 1);
			close(p[0]);
			env = ft_get_comm(cmd[i], env);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			close(p[1]);
			fd_in = p[0]; //save the input for the next command
			i++;
		}
	}
	return (env);
}

char	**ft_op_order(char **args, char **env)
{
	int	op;
	char    **trunc;

	op = ft_next_op(args);
	if (op == 1 || op == 2)
	{
		trunc = ft_trunc_args(args);
		ft_redir_out(args, op);
		env = ft_get_comm(trunc, env);
		if (trunc)
			ft_free_str_arr(trunc);
	}
	else if (op == 3 || op == 4)
	{
		trunc = ft_trunc_args(args);
		ft_redir_in(args, op);
		env = ft_get_comm(trunc, env);
		if (trunc)
			ft_free_str_arr(trunc);
	}
	else if (op == 5)
		env = ft_pipe(args, env);
	else
		env = ft_get_comm(args, env);
	return (env);
}
