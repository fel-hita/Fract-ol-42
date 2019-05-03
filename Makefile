# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 18:52:24 by fel-hita          #+#    #+#              #
#    Updated: 2019/03/18 10:46:25 by fel-hita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
LIBDIR=libs
HEADDIR=includes

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror
LDFLAGS=-I$(HEADDIR) -L$(LIBDIR) -lft -lmlx -lpthread -framework OpenGL -framework AppKit

SRC=$(SRCDIR)/cli.c\
	$(SRCDIR)/display.c\
	$(SRCDIR)/tools.c\
	$(SRCDIR)/events.c\
	$(SRCDIR)/julia.c\
	$(SRCDIR)/julia2.c\

OBJ=$(LIBDIR)/cli.o\
   $(LIBDIR)/display.o\
   $(LIBDIR)/tools.o\
   $(LIBDIR)/events.o\
   $(LIBDIR)/julia.o\
   $(LIBDIR)/julia2.o


NAME=fractol

all: $(NAME)

$(NAME): $(OBJ)
	make re -C $(LIBDIR)/libft
	cp $(LIBDIR)/libft/libft.a $(LIBDIR)/
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean fclean

clean :
	rm -rf $(LIBDIR)/*.o
	rm -rf $(SRCDIR)/*.o
	make clean -C $(LIBDIR)/libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIBDIR)/libft

re: fclean all
