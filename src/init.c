/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 22:48:29 by y0ja              #+#    #+#             */
/*   Updated: 2015/07/03 03:57:44 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		set_canon_vmin(int tty, struct termios *term)
{
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(tty, TCSADRAIN, term) == -1)
		ft_error(GETATTR);
}


static t_dlist	*init_list(int ac, char **av)
{
	int i;
	t_select	box;
	t_dlist		*list;

	i = 1;
	list = NULL;
	while (i < ac)
	{
		box.str = ft_strdup(av[i]);
		box.flags = NO_FLAG;
		ft_dlstadd_end(&list, ft_dlstnew(&box, sizeof(t_select)));
		i++;
	}
	return (list);
}

static int		open_tty(void)
{
	int fd;

	if ((fd = ttyslot()) == -1)
		ft_error(TTYSLOT);
	if (isatty(fd) == 0)
		ft_error(NOTATTY);
	return (fd);
}

void			init_termcap(t_all *all)
{
	char	*termtype;
	int		ret;

	if (!(termtype = getenv("TERM")))
		ft_error(NOTERMENV);
	ret = tgetent(NULL, termtype);
	if (ret < 0)
		ft_error(TERMINFODB);
	if (ret == 0)
		ft_error(TERMNOTDEF);
	if (tcgetattr(all->tty, &all->term) == -1)
		ft_error(GETATTR);
	if (tcgetattr(all->tty, &all->oldterm) == -1)
		ft_error(GETATTR);
	set_canon_vmin(all->tty, &all->term);
	tgetstr_cpb("ti");
	tgetstr_cpb("vi");
}

void			init_all(t_all *all, int ac, char **av)
{
	all->tty = open_tty();
	init_termcap(all);
	signals_handlers();
	all->list = init_list(ac, av);
	all->node = all->list;
	((t_select *)all->node->content)->flags |= F_CURSOR;
	bzero(&all->cursor, sizeof(int) * 2);
	get_size_window(all);
	all->maxlen = get_max_len(all->list);
}
