/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 08:48:05 by rojones           #+#    #+#             */
/*   Updated: 2016/07/29 16:47:51 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include "libft/libft.h"
# include <dirent.h>

typedef struct	s_echo_flag
{
	int	n;
	int	set_e;
}				t_echo_flag;

typedef struct	s_pipe_redir
{
	int	re;
	int	pipe;
	int	reapp;
}				t_pipe_redir;

int				ft_arglen(char *s, int *start);
char			*ft_build_env_var(char **split);
char			**ft_cd(char **args, char **env);
void			ft_cd_home(char **env);
void			ft_cd_opwd(char **env);
int				ft_check_arg_op(char *str);
void			ft_check_arg_case_len(char *line, int *qut, int *i);
int				ft_check_dir(char *path, char *name);
int				ft_check_env_var(char *arg, char **env);
char			*ft_check_qut(char *line);
int				ft_count_arg(char **args);
char			**ft_cpyenv(char **env);
void			ft_echo(char **args, char **env);
char			ft_echo_case(char *str, int *i);
int				ft_echo_env_var(char **env, char *arg);
int				ft_echo_str(char *str);
void			ft_exc_cd(char *path, char **env);
int				ft_exe_path(char **args, char **env);
void			ft_exit(char **split, char **env);
char			**ft_extract_args(char *line);
char			*ft_extract_arg(int len, int start, int *end, char *line);
void			ft_free_str_arr(char **arr);
char			**ft_get_comm(char **args, char **env);
char			*ft_get_env_var(char **env, int ind);
char			*ft_get_redir(char *line);
int				ft_isop(char c);
void			ft_env(char **split, char **env);
char			**ft_launch(char *line, char **env);
int				ft_next_op(char **args);
int				ft_num_args(char *s);
char			**ft_op_order(char **args, char **env);
char			*ft_pwd_var(char *pwd, char *value);
char			**ft_rem_args(char **args);
char			*ft_search_path(char **args, char **env);
char			**ft_setenv(char **split, char **env);
void			ft_skip_space(char *line, int *i);
char			***ft_split_arg_op(char **args);
char			**ft_split_input(char *line, char **env);
char			*ft_str_qut_char(char *str, char c);
char			*ft_sub_arg(char *line, int start, int end);
char			**ft_trunc_args(char **args);
char			**ft_unsetenv(char **split, char **env);
void			ft_update_pwd_env(char **env, char **value, int i);
#endif
