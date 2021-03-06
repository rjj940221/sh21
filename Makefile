# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rojones <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/28 08:54:36 by rojones           #+#    #+#              #
#    Updated: 2016/07/29 16:49:33 by rojones          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sh21
CCFLAGS = gcc -Wall -Werror -Wextra -g3
OBJ = ft_arglen.o ft_build_env_var.o ft_cd.o ft_cd_home.o ft_cd_opwd.o \
	  ft_check_arg_case_len.o ft_check_arg_op.o\
	  ft_check_dir.o ft_check_env_var.o ft_count_arg.o ft_cpyenv.o ft_echo.o \
	  ft_echo_env_var.o ft_echo_str.o ft_env.o ft_echo_case.o \
	  ft_exc_cd.o ft_exe_path.o ft_exit.o ft_extract_arg.o ft_extract_args.o \
	  ft_free_str_arr.o ft_get_comm.o ft_get_env_var.o ft_get_qut.o \
	  ft_get_redir.o ft_isop.o\
	  ft_launch.o ft_pwd_var.o ft_next_op.o  ft_num_args.o ft_op_order.o \
	  ft_rem_args.o ft_split_arg_op.o ft_search_path.o \
	  ft_setenv.o ft_skip_spaces.o ft_split_input.o ft_str_qut_char.o \
	  ft_trunc_args.o ft_unsetenv.o ft_update_env_pwd.o
MAKELIB = make -C libft
MAKELIBCLEAN = make -C libft clean

$(NAME) : $(OBJ)
	$(MAKELIB)
	$(CCFLAGS) -Llibft -lft -o $(NAME) ft_sh21.c $(OBJ)

all : $(NAME)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

ft_arglen.o : ft_arglen.c
	$(CCFLAGS) -c ft_arglen.c

ft_build_env_var.o : ft_build_env_var.c
	$(CCFLAGS) -c ft_build_env_var.c

ft_cd.o : ft_cd.c
	$(CCFLAGS) -c ft_cd.c

ft_cd_home.o : ft_cd_home.c
	$(CCFLAGS) -c ft_cd_home.c

ft_cd_opwd.o : ft_cd_opwd.c
	$(CCFLAGS) -c ft_cd_opwd.c

ft_check_arg_case_len.o : ft_check_arg_case_len.c
	$(CCFLAGS) -c ft_check_arg_case_len.c

ft_check_arg_op.o : ft_check_arg_op.c
	$(CCFLAGS) -c ft_check_arg_op.c

ft_check_dir.o : ft_check_dir.c
	$(CCFLAGS) -c ft_check_dir.c

ft_check_env_var.o : ft_check_env_var.c
	$(CCFLAGS) -c ft_check_env_var.c

ft_count_arg.o : ft_count_arg.c
	$(CCFLAGS) -c ft_count_arg.c

ft_cpyenv.o : ft_cpyenv.c
	$(CCFLAGS) -c ft_cpyenv.c

ft_echo.o : ft_echo.c
	$(CCFLAGS) -c ft_echo.c

ft_echo_env_var.o : ft_echo_env_var.c
	$(CCFLAGS) -c ft_echo_env_var.c

ft_echo_str.o : ft_echo_str.c
	$(CCFLAGS) -c ft_echo_str.c

ft_echo_case.o : ft_echo_case.c
	$(CCFLAGS) -c ft_echo_case.c

ft_env.o : ft_env.c
	$(CCFLAGS) -c ft_env.c

ft_exc_cd.o : ft_exc_cd.c
	$(CCFLAGS) -c ft_exc_cd.c

ft_exe_path.o : ft_exe_path.c
	$(CCFLAGS) -c ft_exe_path.c

ft_exit.o : ft_exit.c
	$(CCFLAGS) -c ft_exit.c

ft_extract_arg.o : ft_extract_arg.c
	$(CCFLAGS) -c ft_extract_arg.c

ft_extract_args.o : ft_extract_args.c
	$(CCFLAGS) -c ft_extract_args.c

ft_free_str_arr.o : ft_free_str_arr.c
	$(CCFLAGS) -c ft_free_str_arr.c

ft_launch.o : ft_launch.c
	$(CCFLAGS) -c ft_launch.c

ft_next_op.o : ft_next_op.c
	$(CCFLAGS) -c ft_next_op.c

ft_num_args.o : ft_num_args.c
	$(CCFLAGS) -c ft_num_args.c

ft_op_order.o : ft_op_order.c
	$(CCFLAGS) -c ft_op_order.c

ft_pwd_var.o : ft_pwd_var.c
	$(CCFLAGS) -c ft_pwd_var.c

ft_get_comm.o : ft_get_comm.c
	$(CCFLAGS) -c ft_get_comm.c

ft_get_env_var.o : ft_get_env_var.c
	$(CCFLAGS) -c ft_get_env_var.c

ft_get_qut.o : ft_get_qut.c
	$(CCFLAGS) -c ft_get_qut.c

ft_get_redir.o : ft_get_redir.c
	$(CCFLAGS) -c ft_get_redir.c

ft_get_op_type.o : ft_get_op_type.c
	$(CCFLAGS) -c ft_get_op_type.c

ft_isop.o : ft_isop.c
	$(CCFLAGS) -c ft_isop.c

ft_rem_args.o : ft_rem_args.c
	$(CCFLAGS) -c ft_rem_args.c

ft_search_path.o : ft_search_path.c
	$(CCFLAGS) -c ft_search_path.c

ft_setenv.o : ft_setenv.c
	$(CCFLAGS) -c ft_setenv.c

ft_skip_spaces.o : ft_skip_spaces.c
	$(CCFLAGS) -c ft_skip_spaces.c

ft_split_arg_op.o : ft_split_arg_op.c
	$(CCFLAGS) -c ft_split_arg_op.c

ft_split_input.o : ft_split_input.c
	$(CCFLAGS) -c ft_split_input.c

ft_str_qut_char.o : ft_str_qut_char.c
	$(CCFLAGS) -c ft_str_qut_char.c

ft_trunc_args.o : ft_trunc_args.c
	$(CCFLAGS) -c ft_trunc_args.c

ft_unsetenv.o : ft_unsetenv.c
	$(CCFLAGS) -c ft_unsetenv.c

ft_update_env_pwd.o : ft_update_env_pwd.c
	$(CCFLAGS) -c ft_update_env_pwd.c
