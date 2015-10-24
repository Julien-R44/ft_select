/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 07:37:41 by sleli42           #+#    #+#             */
/*   Updated: 2015/07/04 02:00:04 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	crash_handler(int sig)
{
	reset_term(f_all(NULL));
	printf("Signal %d receipted.\n", sig);
	exit_select(f_all(NULL));
}

static void	resize_handler(int sig)
{
	tgetstr_cpb("cl");
	get_size_window(f_all(NULL));
	if (f_all(NULL)->win.ws_row <= 3
		|| f_all(NULL)->win.ws_col < f_all(NULL)->maxlen)
	{
		char *res;
		if ((res = tgetstr("cm", NULL)) == NULL)
			ft_error(GETATTR);
		tputs(tgoto(res, (f_all(NULL)->win.ws_col / 2), (f_all(NULL)->win.ws_row / 2)), 0, fputchar);
		ft_putstr("Screen too small.");
	}
	else
		display_choice(f_all(NULL));
}

static void	suspend_handler(int sig)
{
	char cp[2] = {f_all(NULL)->term.c_cc[VSUSP], 0};

	tgetstr_cpb("te");
	tgetstr_cpb("ve");
	if (tcsetattr(f_all(NULL)->tty, 0, &f_all(NULL)->oldterm) == -1)
		ft_error(GETATTR);
	if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)
		ft_error(SIGERR);
	if (ioctl(f_all(NULL)->tty, TIOCSTI, cp) == -1)
		ft_error(IOCTL);
}

static void	sigcont_handler(int sig)
{
	init_termcap(f_all(NULL));
	display_choice(f_all(NULL));
	if (signal(SIGTSTP, suspend_handler) == SIG_ERR)
		ft_error(SIGERR);
}

void		signals_handlers(void)
{
	int sig;

	sig = 0;
	if (signal(SIGWINCH, resize_handler) == SIG_ERR)
		ft_error(SIGERR);
	if (signal(SIGTSTP, suspend_handler) == SIG_ERR)
		ft_error(SIGERR);
	if (signal(SIGCONT, sigcont_handler) == SIG_ERR)
		ft_error(SIGERR);
	while (++sig < 32)
	{
		if (sig == SIGWINCH || sig == SIGKILL || sig == SIGSTOP ||
			sig == SIGTSTP || sig == SIGCONT)
			continue ;
		if (signal(sig, crash_handler) == SIG_ERR)
			ft_error(SIGERR);
	}
}
