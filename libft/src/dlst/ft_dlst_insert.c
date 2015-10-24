/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 02:56:46 by y0ja              #+#    #+#             */
/*   Updated: 2015/01/04 13:41:31 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_insert(t_dlist **list, t_dlist *to_ins)
{
	t_dlist *tmp;
	t_dlist *last;

	if (to_ins == NULL)
		return ;
	if ((*list)->next)
	{
		tmp = (*list)->next;
		last = ft_dlstlast(to_ins);
		last->next = tmp;
		(*list)->next = to_ins;
	}
	else
		ft_dlstadd_end(list, to_ins);
}
