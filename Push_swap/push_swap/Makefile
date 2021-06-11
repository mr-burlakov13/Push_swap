# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhayward <lhayward@student.42.fr>              +#+  +:+       +#+     #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:32:38 by lhayward            #+#    #+#            #
#    Updated: 2021/01/09 20:11:19 by lhayward           ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap

NAME2	:= checker

BONUS	:= checker_bonus

CC		:=	gcc
FLAG	:=	-Wall -Wextra -Werror -I include -I ../checker/include 
RM		:=	rm -rf

INC_D	:=	./include/
LIBMLX 	:=  ../bonus/mlx_dynamic/libmlx.dylib
INC		:=	push_swap.h
SRCS	:=	push_swap.c ../function/ft_swap.c ../function/rr_pa.c ../function/rr_dop.c ../function/valid.c pre_work.c find_min_elem.c pervaya_polovina.c vtoraya_polovina.c d_4_xp.c sort_part_2.c sort_part_1.c sort2_ku_1.c sort2_ku_2.c ../function/liba.c sort_2_3_4.c ../function/get_next_line_utils.c ../function/get_next_line.c
SRCS2	:=  ../checker/checker.c ../function/ft_swap.c ../function/rr_pa.c ../function/rr_dop.c ../function/valid.c ../function/get_next_line_utils.c ../function/get_next_line.c ../function/liba.c
SRCS_BONUS	:=  ../bonus/checker.c ../bonus/dop.c ../bonus/close.c ../function/ft_swap.c ../function/rr_pa.c ../function/rr_dop.c ../function/valid.c ../function/get_next_line_utils.c ../function/get_next_line.c ../function/liba.c
all:	$(NAME) $(NAME2)

bonus:	${BONUS}

${NAME}: ${SRCS} ${INC_D}${INC}
			${CC} ${FLAG} ${SRCS} -o $(NAME)

${NAME2}: ${SRCS2} ${INC_D}${INC}
			${CC} ${FLAG} ${SRCS2} -o $(NAME2)

${LIBMLX}:
	make -C ../bonus/mlx_dynamic

${BONUS}: ${LIBMLX} ${SRCS_BONUS}
			cp ../bonus/mlx_dynamic/libmlx.dylib .
			${CC} ${FLAG} ${SRCS_BONUS} -o $(BONUS) -I ../bonus/include_b -I ../bonus/mlx_dynamic libmlx.dylib -I include -I ../checker/include 

clean:
	@make clean -C ../bonus/mlx_dynamic

fclean:		clean
	@rm -f ${NAME}
	@rm -f ${NAME2}
	@rm -f ${BONUS}
re:     fclean all
