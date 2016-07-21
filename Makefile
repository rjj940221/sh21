# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rojones <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/28 08:54:36 by rojones           #+#    #+#              #
#    Updated: 2016/07/20 17:51:51 by rojones          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sh21
CCFLAGS = gcc -Wall -Werror -Wextra -g3
OBJ = ft_arglen.o ft_build_env_var.o ft_cd.o ft_cd_home.o ft_cd_opwd.o \
	  ft_check_arg_case_len.o\
	  ft_check_dir.o ft_check_env_var.o ft_count_arg.o ft_cpyenv.o ft_echo.o \
	  ft_echo_env_var.o ft_echo_str.o ft_env.o ft_echo_case.o \
	  ft_exc_cd.o ft_extract_arg.o ft_extract_args.o \
	  ft_free_str_arr.o ft_get_comm.o ft_get_env_var.o ft_launch.o \
	  ft_pwd_var.o ft_num_args.o ft_search_path.o ft_setenv.o \
	  ft_skip_spaces.o ft_unsetenv.o ft_update_env_pwd.o
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

ft_extract_arg.o : ft_extract_arg.c
	$(CCFLAGS) -c ft_extract_arg.c

ft_extract_args.o : ft_extract_args.c
	$(CCFLAGS) -c ft_extract_args.c

ft_free_str_arr.o : ft_free_str_arr.c
	$(CCFLAGS) -c ft_free_str_arr.c

ft_launch.o : ft_launch.c
	$(CCFLAGS) -c ft_launch.c

ft_num_args.o : ft_num_args.c
	$(CCFLAGS) -c ft_num_args.c

ft_pwd_var.o : ft_pwd_var.c
	$(CCFLAGS) -c ft_pwd_var.c

ft_get_comm.o : ft_get_comm.c
	$(CCFLAGS) -c ft_get_comm.c

ft_get_env_var.o : ft_get_env_var.c
	$(CCFLAGS) -c ft_get_env_var.c

ft_search_path.o : ft_search_path.c
	$(CCFLAGS) -c ft_search_path.c

ft_setenv.o : ft_setenv.c
	$(CCFLAGS) -c ft_setenv.c

ft_skip_spaces.o : ft_skip_spaces.c
	$(CCFLAGS) -c ft_skip_spaces.c

ft_unsetenv.o : ft_unsetenv.c
	$(CCFLAGS) -c ft_unsetenv.c

ft_update_env_pwd.o : ft_update_env_pwd.c
	$(CCFLAGS) -c ft_update_env_pwd.c
