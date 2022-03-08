# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 14:27:46 by snpark            #+#    #+#              #
#    Updated: 2022/03/07 16:34:26 by snpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src			= main.cpp
obj			= $(src:%.cpp=%.o)
flags		= -Wall -Werror -Wextra -std=c++98
NAME		= ft_containers 
compiler	= clang++

%.o			: %.cpp
	$(compiler)	$(flags) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(obj)
	$(compiler)	$(flags) $(obj) -o $(NAME)
	
clean		:
	rm -rf $(obj)

fclean		: clean
	rm -rf $(NAME)

re			: fclean all
