# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 08:53:45 by ccorsin           #+#    #+#              #
#    Updated: 2018/02/09 10:27:11 by ccorsin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

_SRCS = ft_affichage.c \
		ft_flag_ls.c \
		ft_ls_file.c \
		ft_ls_repo.c \
		ft_sort.c \
		main.c \
		ft_annex.c \
		ft_list.c \
		ft_sort_list.c \
		ft_annex2.c \
		ft_comp.c \
		ft_init_free.c \
		ft_for_d.c \
		ft_build_list.c

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))
SRCO = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME)

$(NAME) : $(SRCO)
	make -C libft
	gcc $(FLAGS) -Llibft -lft -o $(NAME) $(SRCO) libft/libft.a

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO)
	make clean -C libft

fclean : clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re :
	make fclean
	make
