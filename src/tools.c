 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 03:48:14 by y0ja              #+#    #+#             */
/*   Updated: 2015/03/31 22:42:18 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
	us = Underlining Set
	ue = Underlining End
	mr = Mode Reversed
	cl = Clear window

	ti = Terminal Init (full screen pref.)
	te = Terminal End

	vb = Psyche Mode

	vi = Cursor Invisible
	ve = Cursor Normal

	ho = Cursor Home Position
	cr = Carriage Return

*/
void	tgetstr_cpb(char *cpb)
{
	char *res;

	if ((res = tgetstr(cpb, NULL)) == NULL)
		ft_error(GETATTR);
	tputs(res, 0, fputchar);
}

void	get_size_window(t_all *all)
{
	if (ioctl(all->tty, TIOCGWINSZ, &all->win) == -1)
		ft_error(IOCTL);
}

int		get_max_len(t_dlist *nav)
{
	int maxlen;
	int ret;

	maxlen = 0;
	while (nav)
	{
		ret = ft_strlen(((t_select *)nav->content)->str);
		if (ret > maxlen)
			maxlen = ret;
		nav = nav->next;
	}
	return (maxlen);
}

void	cursor_move_to(int x, int y)
{
	char *res;

	if ((res = tgetstr("cm", NULL)) == NULL)
		ft_error(GETATTR);
	tputs(tgoto(res, x, y), 0, fputchar);
}

t_all	*f_all(t_all *all)
{
	static t_all	*ret = NULL;

	if (ret == NULL)
		ret = all;
	return (ret);
}
