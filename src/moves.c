/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 03:45:33 by y0ja              #+#    #+#             */
/*   Updated: 2015/07/04 01:58:38 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

# define GO_FIRST 1
# define GO_LAST 2
# define GO_NORM 0

static int		change_select(t_dlist **node, int vec)
{
	t_dlist *next_node;
	t_dlist *(*circular_function)(t_dlist *);
	int ret;

	if (vec == 1)
	{
		next_node = (*node)->next;
		circular_function = &ft_dlstfirst;
		ret = GO_FIRST;
	}
	else if (vec == -1)
	{
		next_node = (*node)->before;
		circular_function = &ft_dlstlast;
		ret = GO_LAST;
	}
	if (next_node == NULL)
		next_node = circular_function(*node);
	else
		ret = GO_NORM;
	((t_select *)(*node)->content)->flags ^= F_CURSOR;
	((t_select *)next_node->content)->flags |= F_CURSOR;
	*node = next_node;
	return (ret);
}

void	del_node(t_dlist **node, t_dlist **list)
{
	t_dlist *tmp;
	int vec;

	if ((*node)->next == NULL && (*node)->before == NULL)
		reset_and_exit(f_all(NULL));
	vec = change_select(&(*node), 1);
	if (vec == GO_NORM)
		ft_dlstdelone(&(*node)->before, f_deleter);
	if (vec == GO_FIRST)
	{
		tmp = ft_dlstlast(*node);
		ft_dlstdelone(&tmp, f_deleter);
	}
}

void	cursor_vertical_move(t_all *all, int vector)
{
	change_select(&all->node, vector);
}

void			cursor_horizont_move(t_all *all, int vector)
{
	char *res;

	if (all->cursor.y + vector <= -1)
		return ;
	all->cursor.x += vector;
	cursor_move_to(all->cursor.x, all->cursor.y);
}
