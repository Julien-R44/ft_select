/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 00:11:06 by y0ja              #+#    #+#             */
/*   Updated: 2014/11/21 10:37:26 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstrev(t_dlist **list)
{
	t_dlist	*nav;
	t_dlist *last;
	int		len;

	nav = *list;
	len = (ft_dlstlen(*list) / 2);
	last = ft_dlstlast(*list);
	while (len)
	{
		ft_swap_contents(&nav, &last);
		nav = nav->next;
		last = last->before;
		len--;
	}
}
