/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 19:13:03 by y0ja              #+#    #+#             */
/*   Updated: 2015/07/04 01:42:50 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	return_choice(t_all *all)
{
	t_dlist	*nav;
	int fd;

	nav = all->list;
	reset_term(all);
	while (nav)
	{
		if (((t_select *)nav->content)->flags & F_SELECT)
		{
			ft_putstr(((t_select *)nav->content)->str);
			if (nav->next && ((t_select *)nav->next->content)->flags & F_SELECT)
				ft_putchar(' ');
			else
				ft_putchar('\n');
		}
		nav = nav->next;
	}
	exit_select(all);
}

int		get_key(t_all *all)
{
	char buf[3] = {0};

	read(all->tty, buf, 3);
	if (K_ISTOP)
		cursor_vertical_move(all, -1);
	else if (K_ISBOT)
		cursor_vertical_move(all, 1);
	else if (K_ISLEFT)
		cursor_horizont_move(all, -(all->maxlen + 2));
	else if (K_ISRIGHT)
		cursor_horizont_move(all, all->maxlen + 2);
	else if (K_ISSPACE)
		((t_select *)all->node->content)->flags ^= F_SELECT;
	else if (K_ISSUPR || K_ISBACKS)
		del_node(&all->node, &all->list);
	else if (K_ISENTER)
		return_choice(all);
	else if (K_ISECHAP)
		return (-1);
	return (1);
}

void	main_loop(t_all *all)
{
	tgetstr_cpb("cl");
	while (77)
	{
		display_choice(all);
		if (get_key(all) == -1)
			break ;
		tgetstr_cpb("cl");
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	f_all(&all);
	if (ac < 2)
		ft_error(NOARGS);
	init_all(&all, ac, av);
	main_loop(&all);
	reset_and_exit(&all);
	return (0);
}
