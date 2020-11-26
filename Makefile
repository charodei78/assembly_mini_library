# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/11 14:27:14 by hheimerd          #+#    #+#              #
#    Updated: 2020/10/23 16:47:33 by hheimerd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AFLAGS			= -f macho64
ASMC			= nasm
CC				= clang
NAME 			= libasm.a
ASRC			= ft_strlen.s \
				  ft_strcpy.s \
				  ft_write.s \
				  ft_read.s \
				  ft_strdup.s \
				  ft_strcmp.s
ASM_OBJ			= $(ASRC:.s=.o)
CSRC			= main.c
C_OBJ			= $(CSRC:.c=.o)

all: $(NAME)

$(NAME): $(ASM_OBJ)

check: $(NAME) $(C_OBJ)
	gcc $(C_OBJ) -g $(NAME)
	touch test
	@echo "========START========"
	./a.out
	@echo "========FINISH========"
	rm a.out test

clean:
	rm -f $(C_OBJ) $(ASM_OBJ) $(HEADER_OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.c.o:
	$(CC) -c $<

.s.o:
	$(ASMC) $(AFLAGS) $<
	ar rcs $(NAME) $@
