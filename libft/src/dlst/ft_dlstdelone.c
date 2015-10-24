/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 05:04:02 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/10 02:42:59 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		default_deleter(void *data, size_t size)
{
	(void)size;
	ft_memdel(&data);
}

static void		replace_node(t_dlist **alst, t_dlist *node, int m)
{
	*alst = node;
	if (m == 1)
		(*alst)->before = NULL;
	else
		(*alst)->next = NULL;
}

void			ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*prev_link;
	t_dlist		*next_link;

	prev_link = (*alst)->before;
	next_link = (*alst)->next;
	if (del == NULL)
		del = default_deleter;
	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
	if (next_link && !prev_link)
		replace_node(alst, next_link, 1);
	else if (prev_link && !next_link)
		replace_node(alst, prev_link, 0);
	else if (prev_link && next_link)
	{
		*alst = prev_link;
		prev_link->next = next_link;
		next_link->before = prev_link;
	}
}
