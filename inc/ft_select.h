/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:49:42 by y0ja              #+#    #+#             */
/*   Updated: 2015/07/04 02:11:45 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <curses.h>
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define K_ISECHAP	(buf[0] == 27 && (!buf[1] && !buf[2]))
# define K_ISTOP	(buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
# define K_ISBOT	(buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
# define K_ISRIGHT	(buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
# define K_ISLEFT	(buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
# define K_ISSPACE	(buf[0] == 32 && (!buf[1] && !buf[2]))
# define K_ISSUPR	(buf[0] == 27 && buf[1] == 91 && buf[2] == 51)
# define K_ISBACKS	(buf[0] == 127 && !(buf[1] && !(buf[2])))
# define K_ISENTER	(buf[0] == 10 && !(buf[1] && !(buf[2])))

# define NO_FLAG	0
# define F_SELECT	1
# define F_CURSOR	2

// Signaux, del
//
typedef enum		s_er
{
	NOTERMENV,
	TERMINFODB,
	TERMNOTDEF,
	GETATTR,
	TTYSLOT,
	NOTATTY,
	NOARGS,
	IOCTL,
	SIGERR,
}					t_er;

typedef struct		s_select
{
	unsigned int	flags;
	char			*str;
}					t_select;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_all
{
	struct termios	oldterm;
	struct termios	term;
	struct winsize	win;
	t_dlist			*list;
	t_dlist			*node;
	t_pos			cursor;
	int				tty;
	int				maxlen;
}					t_all;

// ft_select
t_all				*f_all(t_all *all);
void				init_all(t_all *all, int ac, char **av);
void				init_termcap(t_all *all);
void				display_choice(t_all *all);
void				signals_handlers(void);
void				ft_error(int er);

// moves.c
void				cursor_vertical_move(t_all *all, int vector);
void				cursor_horizont_move(t_all *all, int vector);
void				del_node(t_dlist **node, t_dlist **list);
void				get_size_window(t_all *all);

// tools.c
void				tgetstr_cpb(char *cpb);
int					get_max_len(t_dlist *nav);
void				cursor_move_to(int x, int y);
t_all				*f_all(t_all *all);

// misc
void				f_deleter(void *box, size_t size);
void				reset_and_exit(t_all *all);
void				exit_select(t_all *all);
void				reset_term(t_all *all);
int					fputchar(int c);

#endif
