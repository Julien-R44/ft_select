/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 23:20:52 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/17 14:53:20 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_end(t_dlist **alst, t_dlist *new)
{
	t_dlist *nav;

	if (new && *alst)
	{
		nav = *alst;
		while (nav->next != NULL)
			nav = nav->next;
		nav->next = new;
		new->before = nav;
	}
	else
		*alst = new;
}
