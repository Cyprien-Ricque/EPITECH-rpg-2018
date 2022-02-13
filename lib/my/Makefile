##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	gnl.o	\
		m_cisnb.o	\
		m_printf.o	\
		m_spelen.o	\
		m_scpy.o	\
		free_array.o	\
		m_alen.o	\
		m_intuses.o	\
		p_iflag.o	\
		m_realloc.o	\
		m_intarraylen.o	\
		p_flag.o	\
		m_realloc.o	\
		m_template.o	\
		m_arraydup.o	\
		m_arraycat.o	\
		m_getnb.o	\
		m_sarray.o	\
		m_scat.o	\
		m_sisnb.o	\
		m_arraylen.o	\
		m_cleans.o	\
		m_putarray.o	\
		m_arrays.o	\
		m_puts.o	\
		m_retbase.o	\
		m_revs.o	\
		m_sdup.o	\
		m_slen.o	\
		cut.o	\
		m_sisnb.o	\
		m_scmp_case.o	\
		rm_spaces.o	\
		m_scmp.o

CFLAGS	=	-W -Wall -Wextra

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(SRC)
	@ar rc $(NAME) $^
	@printf "[\033[0;32mlib built\033[0m]"
	@printf "%50s\n" $(NAME) | tr ' ' '.'

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@printf "[\033[0;36mcompiled\033[0m] % 50s\n" $< | tr ' ' '.'

clean:
	@rm -f $(SRC)
	@printf "[\033[0;31mremoved\033[0m] % 50s\n" $(SRC) | tr ' ' '.'


fclean:	clean
	@rm -f $(NAME)
	@printf "[\033[0;31mremoved\033[0m] % 50s\n" $(NAME) | tr ' ' '.'

re:	fclean all
