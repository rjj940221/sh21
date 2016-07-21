# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rojones <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/11 13:16:09 by rojones           #+#    #+#              #
#    Updated: 2016/07/20 17:34:17 by rojones          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
C = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -c
OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_free_str_arr.o\
	ft_atoi_base.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o \
	ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o \
	ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o \
	ft_atoi.o ft_ishex.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
	ft_isprint.o ft_toupper.o ft_tolower.o ft_memalloc.o ft_memdel.o \
	ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o \
	ft_power.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o \
	ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o \
	ft_putstr.o ft_putendl.o  ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o \
	ft_putendl_fd.o ft_putnbr_fd.o ft_strcmp.o ft_strncmp.o ft_lstnew.o \
   	ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
	ft_isspace.o get_next_line.o ft_newword.o ft_wordlen.o ft_numwords.o\
	ft_lstaddend.o ft_convert.o ft_modifiers.o ft_nummoders.o ft_pad.o\
	ft_printf.o ft_printnumber.o ft_printstring.o ft_flags.o ft_printchar.o

$(NAME): all

all: $(OBJ) 
	ar rc libft.a $(OBJ)

clean: 
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f libft.a

re: fclean all

ft_atoi_base.o : ft_atoi_base.c
	$(C) $(CFLAGS) ft_atoi_base.c

ft_memset.o : ft_memset.c
	$(C) $(CFLAGS) ft_memset.c

ft_bzero.o : ft_bzero.c
	$(C) $(CFLAGS) ft_bzero.c

ft_memcpy.o : ft_memcpy.c
	$(C) $(CFLAGS) ft_memcpy.c

ft_memccpy.o : ft_memccpy.c
	$(C) $(CFLAGS) ft_memccpy.c

ft_memmove.o : ft_memmove.c
	$(C) $(CFLAGS) ft_memmove.c

ft_memchr.o : ft_memchr.c
	$(C) $(CFLAGS) ft_memchr.c

ft_memcmp.o : ft_memcmp.c
	$(C) $(CFLAGS) ft_memcmp.c

ft_strlen.o : ft_strlen.c
	$(C) $(CFLAGS) ft_strlen.c

ft_strdup.o : ft_strdup.c
	$(C) $(CFLAGS) ft_strdup.c

ft_strcpy.o : ft_strcpy.c
	$(C) $(CFLAGS) ft_strcpy.c

ft_strncpy.o : ft_strncpy.c
	$(C) $(CFLAGS) ft_strncpy.c

ft_strcat.o : ft_strcat.c
	$(C) $(CFLAGS) ft_strcat.c

ft_strncat.o : ft_strncat.c
	$(C) $(CFLAGS) ft_strncat.c

ft_strlcat.o : ft_strlcat.c
	$(C) $(CFLAGS) ft_strlcat.c

ft_strchr.o : ft_strchr.c
	$(C) $(CFLAGS) ft_strchr.c

ft_strrchr.o : ft_strrchr.c
	$(C) $(CFLAGS) ft_strrchr.c

ft_strstr.o : ft_strstr.c
	$(C) $(CFLAGS) ft_strstr.c

ft_strnstr.o : ft_strnstr.c
	$(C) $(CFLAGS) ft_strnstr.c

ft_strcmp.o : ft_strcmp.c
	$(C) $(CFLAGS) ft_strcmp.c

ft_strncmp.o : ft_strncmp.c
	$(C) $(CFLAGS) ft_strncmp.c

ft_atoi.o : ft_atoi.c
	$(C) $(CFLAGS) ft_atoi.c

ft_isalpha.o : ft_isalpha.c
	$(C) $(CFLAGS) ft_isalpha.c

ft_isdigit.o : ft_isdigit.c
	$(C) $(CFLAGS) ft_isdigit.c

ft_isalnum.o : ft_isalnum.c
	$(C) $(CFLAGS) ft_isalnum.c

ft_isascii.o : ft_isascii.c
	$(C) $(CFLAGS) ft_isascii.c

ft_ishex.o : ft_ishex.c
	$(C) $(CFLAGS) ft_ishex.c

ft_isprint.o : ft_isprint.c
	$(C) $(CFLAGS) ft_isprint.c

ft_toupper.o : ft_toupper.c
	$(C) $(CFLAGS) ft_toupper.c

ft_tolower.o : ft_tolower.c
	$(C) $(CFLAGS) ft_tolower.c

ft_memalloc.o : ft_memalloc.c
	$(C) $(CFLAGS) ft_memalloc.c

ft_memdel.o : ft_memdel.c
	$(C) $(CFLAGS) ft_memdel.c

ft_strnew.o : ft_strnew.c
	$(C) $(CFLAGS) ft_strnew.c

ft_strdel.o : ft_strdel.c
	$(C) $(CFLAGS) ft_strdel.c

ft_strclr.o : ft_strclr.c
	$(C) $(CFLAGS) ft_strclr.c

ft_striter.o : ft_striter.c
	$(C) $(CFLAGS) ft_striter.c

ft_striteri.o : ft_striteri.c
	$(C) $(CFLAGS) ft_striteri.c

ft_strmap.o : ft_strmap.c
	$(C) $(CFLAGS) ft_strmap.c

ft_strmapi.o : ft_strmapi.c
	$(C) $(CFLAGS) ft_strmapi.c

ft_strequ.o : ft_strequ.c
	$(C) $(CFLAGS) ft_strequ.c

ft_strnequ.o : ft_strnequ.c
	$(C) $(CFLAGS) ft_strnequ.c

ft_strsub.o : ft_strsub.c
	$(C) $(CFLAGS) ft_strsub.c

ft_power.o : ft_power.c
	$(C) $(CFLAGS) ft_power.c

ft_strjoin.o : ft_strjoin.c
	$(C) $(CFLAGS) ft_strjoin.c

ft_strtrim.o : ft_strtrim.c
	$(C) $(CFLAGS) ft_strtrim.c

ft_strsplit.o : ft_strsplit.c
	$(C) $(CFLAGS) ft_strsplit.c

ft_itoa.o : ft_itoa.c
	$(C) $(CFLAGS) ft_itoa.c

ft_putchar.o : ft_putchar.c
	$(C) $(CFLAGS) ft_putchar.c

ft_putstr.o : ft_putstr.c
	$(C) $(CFLAGS) ft_putstr.c

ft_putendl.o : ft_putendl.c
	$(C) $(CFLAGS) ft_putendl.c

ft_putnbr.o : ft_putnbr.c
	$(C) $(CFLAGS) ft_putnbr.c

ft_putchar_fd.o : ft_putchar_fd.c
	$(C) $(CFLAGS) ft_putchar_fd.c

ft_putstr_fd.o : ft_putstr_fd.c
	$(C) $(CFLAGS) ft_putstr_fd.c

ft_putendl_fd.o : ft_putendl_fd.c
	$(C) $(CFLAGS) ft_putendl_fd.c

ft_putnbr_fd.o : ft_putnbr_fd.c
	$(C) $(CFLAGS) ft_putnbr_fd.c

ft_lstnew.o : ft_lstnew.c
	$(C) $(CFLAGS) ft_lstnew.c

ft_lstdelone.o : ft_lstdelone.c
	$(C) $(CFLAGS) ft_lstdelone.c

ft_lstdel.o : ft_lstdel.c
	$(C) $(CFLAGS) ft_lstdel.c

ft_lstadd.o : ft_lstadd.c
	$(C) $(CFLAGS) ft_lstadd.c

ft_lstiter.o : ft_lstiter.c
	$(C) $(CFLAGS) ft_lstiter.c

ft_lstmap.o : ft_lstmap.c
	$(C) $(CFLAGS) ft_lstmap.c

ft_isspace.o : ft_isspace.c
	$(C) $(CFLAGS) ft_isspace.c

get_next_line.o : get_next_line.c
	$(C) $(CFLAGS) get_next_line.c

ft_newword.o : ft_newword.c
	$(C) $(CFLAGS) ft_newword.c

ft_wordlen.o : ft_wordlen.c
	$(C) $(CFLAGS) ft_wordlen.c

ft_numwords.o : ft_numwords.c
	$(C) $(CFLAGS) ft_numwords.c

ft_lstaddend.o : ft_lstaddend.c
	$(C) $(CFLAGS) ft_lstaddend.c

ft_convert.o : ft_convert.c
	$(C) $(CFLAGS) ft_convert.c

ft_flags.o : ft_flags.c
	$(C) $(CFLAGS) ft_flags.c

ft_free_str_arr.o : ft_free_str_arr.c
	$(C) $(CFLAGS) ft_free_str_arr.c

ft_modifiers.o : ft_modifiers.c
	$(C) $(CFLAGS) ft_modifiers.c

ft_nummoders.o : ft_nummoders.c
	$(C) $(CFLAGS) ft_nummoders.c

ft_pad.o : ft_pad.c
	$(C) $(CFLAGS) ft_pad.c

ft_printf.o : ft_printf.c
	$(C) $(CFLAGS) ft_printf.c

ft_printnumber.o : ft_printnumber.c
	$(C) $(CFLAGS) ft_printnumber.c

ft_printstring.o : ft_printstring.c
	$(C) $(CFLAGS) ft_printstring.c

ft_printchar.o : ft_printchar.c
	$(C) $(CFLAGS) ft_printchar.c
