# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 08:53:45 by ccorsin           #+#    #+#              #
#    Updated: 2018/01/30 14:22:46 by ccorsin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

_LSRCS = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strlcat.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_strndup.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_power.c \
		ft_countwords.c \
		get_next_line.c \
		ft_putwchar.c \
		ft_putwstr.c \
		ft_strchr_rev.c

_SRCS = ft_strzero.c \
		ft_strspace.c \
		ft_printf.c \
		ft_attribut.c \
		ft_champ.c \
		ft_champ2.c \
		ft_conversion.c \
		ft_flag.c \
		ft_precision.c \
		ft_string1.c \
		ft_string2.c \
		ft_string3.c \
		ft_string4.c \
		ft_string5.c \
		ft_itoaintmax.c \
		ft_itoalgint.c \
		ft_itoalglgint.c \
		ft_itoabase.c \
		ft_itoallbase.c \
		ft_itoaulgint.c \
		ft_base.c \
		ft_putstrtot.c \
		ft_putwstrsub.c \
		ft_star.c

SRCS_DIR = librairie
LSRCS_DIR = librairie
SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))
LSRCS = $(addprefix $(LSRCS_DIR)/, $(_LSRCS))
SRCO = $(SRCS:.c=.o)
LSRCO = $(LSRCS:.c=.o)
SRCO += $(LSRCO)

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME)

$(NAME) : $(SRCO)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO)

fclean : clean
	/bin/rm -f $(NAME)

re :
	make fclean
	make
