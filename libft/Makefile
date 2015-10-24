# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 00:27:00 by jripoute          #+#    #+#              #
#    Updated: 2015/03/08 23:02:10 by jripoute         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
LDFLAGS	= -I./include/
SRC		= \
		atoi/ft_atoi.c \
		atoi/ft_itoa.c \
		atoi/ft_llitoa.c \
		atoi/ft_ullitoa.c \
		lst/ft_lstadd.c \
		lst/ft_lstadd_end.c \
		lst/ft_lstadd_i.c \
		lst/ft_lstati.c \
		lst/ft_lstdel.c \
		lst/ft_lstdelone.c \
		lst/ft_lstiter.c \
		lst/ft_lstlast.c \
		lst/ft_lstlen.c \
		lst/ft_lstmap.c \
		lst/ft_lstnew.c \
		dlst/ft_dlst_insert.c \
		dlst/ft_dlstadd.c \
		dlst/ft_dlstadd_end.c \
		dlst/ft_dlstadd_i.c \
		dlst/ft_dlstati.c \
		dlst/ft_dlstdel.c \
		dlst/ft_dlstdelone.c \
		dlst/ft_dlstfirst.c \
		dlst/ft_dlstlast.c \
		dlst/ft_dlstlen.c \
		dlst/ft_dlstnew.c \
		dlstc/ft_dlstcnew.c \
		dlstc/ft_dlstcadd.c \
		dlstc/ft_dlstcpop.c \
		dlstc/ft_dlstcpush.c \
		dlstc/ft_dlstcfirst.c \
		dlstc/ft_dlstclast.c \
		dlstc/ft_dlstcclear.c \
		dlstc/ft_dlstcdel_one.c \
		dlstc/ft_dlstcdel.c \
		dlst/ft_dlstrev.c \
		dlst/ft_swap_contents.c \
		misc/ft_intlen.c \
		misc/ft_rand_a_b.c \
		misc/ft_rotn.c \
		misc/ft_tolower.c \
		misc/ft_toupper.c \
		misc/get_next_line.c \
		mem/ft_bzero.c \
		mem/ft_memalloc.c \
		mem/ft_memccpy.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memdel.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \
		mem/ft_realloc.c \
		put/ft_printdlist.c \
		put/ft_printlist.c \
		put/ft_putaddr.c \
		put/ft_putchar.c \
		put/ft_putchar_fd.c \
		put/ft_putendl.c \
		put/ft_putendl_fd.c \
		put/ft_putnbr.c \
		put/ft_putnbr_fd.c \
		put/ft_putnchar.c \
		put/ft_putstr.c \
		put/ft_putstr_fd.c \
		is/ft_isalnum.c \
		is/ft_isalpha.c \
		is/ft_isascii.c \
		is/ft_isdigit.c \
		is/ft_islower.c \
		is/ft_isprint.c \
		is/ft_isspace.c \
		is/ft_isupper.c \
		str/ft_charcount.c \
		str/ft_strcasecmp.c \
		str/ft_strcat.c \
		str/ft_strchr.c \
		str/ft_strchrstr.c \
		str/ft_strclen.c \
		str/ft_strclr.c \
		str/ft_strcmp.c \
		str/ft_strcpy.c \
		str/ft_strdel.c \
		str/ft_strdup.c \
		str/ft_strequ.c \
		str/ft_striter.c \
		str/ft_striteri.c \
		str/ft_strjoin.c \
		str/ft_strlcat.c \
		str/ft_strlen.c \
		str/ft_strmap.c \
		str/ft_strmapi.c \
		str/ft_strncat.c \
		str/ft_strncmp.c \
		str/ft_strncpy.c \
		str/ft_strndup.c \
		str/ft_strnequ.c \
		str/ft_strnew.c \
		str/ft_strnstr.c \
		str/ft_strrchr.c \
		str/ft_strrev.c \
		str/ft_strsplit.c \
		str/ft_strstr.c \
		str/ft_strsub.c \
		str/ft_strtrim.c \
		wstr/ft_putwchar.c \
		wstr/ft_putwcs.c \
		wstr/ft_wcscat.c \
		wstr/ft_wcscpy.c \
		wstr/ft_wcsdup.c \
		wstr/ft_wcslen.c \
		wstr/ft_wcsequ.c

SRCDIR	= ./src/
OBJDIR	= ./obj/
INCDIR	= ./include/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS 	= $(addprefix $(OBJDIR), $(patsubst %.c, %.o,$(SRC)))
INCS	= $(addprefix -I , $(INCDIR))
DIRSOBJ	= $(sort $(dir $(OBJS)))
DEBUG=no
ifeq ($(DEBUG),no)
	CFLAGS = -Wall -Wextra -Werror
else
	CFLAGS = -g
endif

.PHONY: clean fclean re

.SILENT:

all: $(NAME)

$(NAME): makedir $(OBJS)
	echo "\\033[1;34mIndexing the lib...\\033[0;39m"
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "\\033[1;32mSuccess.\\033[0;39m"

makedir:
ifeq ($(DEBUG),no)
	echo "\\033[1;31mDebug compilation.. (-Wall -Wextra -Werror)\\033[0;39m"
else
	echo "\\033[1;31mNo flags.\\033[0;39m"
endif
	echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
	mkdir -p $(OBJDIR)
	mkdir -p $(DIRSOBJ)

$(OBJDIR)%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $< $(INCS) $(CFLAGS)

clean:
	echo "\\033[1;34mDeleting objects...\\033[0;39m"
	rm -f $(OBJS)

fclean: clean
	echo "\\033[1;34mDeleting libft.a...\\033[0;39m"
	rm -f $(NAME)

re: fclean all
