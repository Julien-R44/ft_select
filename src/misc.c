/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 22:49:05 by y0ja              #+#    #+#             */
/*   Updated: 2015/07/04 02:08:18 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	f_deleter(void *box, size_t size)
{
	free(((t_select *)box)->str);
	ft_memdel(&box);
}

void	reset_term(t_all *all)
{
	tgetstr_cpb("te");
	tgetstr_cpb("ve");
	if (tcsetattr(all->tty, 0, &all->oldterm) == -1)
		ft_error(GETATTR);
}

void	exit_select(t_all *all)
{
	ft_dlstdel(&all->list, &f_deleter);
	ft_dlstdel(&all->node, &f_deleter);
	exit(0);
}

void	reset_and_exit(t_all *all)
{
	reset_term(all);
	exit_select(all);
}

void	ft_error(int er)
{
	if (er == NOTERMENV)
		printf("Specify terminal with setenv TERM.\n");
	else if (er == TERMINFODB)
		printf("Terminfo database could not be found.\n");
	else if (er == TERMNOTDEF)
		printf("Specified term is not defined.\n");
	else if (er == GETATTR)
		printf("tcgetattr() | tcsetattr() | tgetX() failed.\n");
	else if (er == TTYSLOT)
		printf("Terminal's fd wasn't found.\n");
	else if (er == NOTATTY)
		printf("The FD is not a valid terminal.\n");
	else if (er == SIGERR)
		printf("signal() returned SIG_ERR.\n");
	else if (er == NOARGS)
		printf("./ft_select <choices...> \n");
	exit(-1);
}

int		fputchar(int c)
{
	ft_putchar_fd(c, 2);
	return (1);
}
