/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 05:51:33 by y0ja              #+#    #+#             */
/*   Updated: 2015/07/03 02:42:15 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		display_select(t_select *box, int fd)
{
	if (box->flags & F_SELECT)
		tgetstr_cpb("mr");
	if (box->flags & F_CURSOR)
		tgetstr_cpb("us");
	ft_putstr_fd(box->str, fd);
	if (box->flags & F_SELECT)
		tgetstr_cpb("me");
	if (box->flags & F_CURSOR)
		tgetstr_cpb("ue");
}

static void		other_row_plz(int *y, int *x, int maxlen)
{
	*y = 0;
	*x += maxlen + 2;
}

void			display_choice(t_all *all)
{
	t_dlist	*nav;
	char	*res;
	int		y;
	int		x;

	y = 1;
	x = 0;
	nav = all->list;
	tgetstr_cpb("ho");
	if ((res = tgetstr("cm", NULL)) == NULL)
		ft_error(GETATTR);
	while (nav)
	{
		display_select(nav->content, all->tty);
		if (y == all->win.ws_row)
			other_row_plz(&y, &x, all->maxlen);
		tputs(tgoto(res, x, y), 1, fputchar);
		nav = nav->next;
		y++;
	}
	cursor_move_to(all->cursor.x, all->cursor.y);
}
