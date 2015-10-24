/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:06:23 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/14 17:02:48 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_i(t_list **list, t_list *lst_new, unsigned int n)
{
	t_list			*prec;
	t_list			*nav;
	unsigned int	i;

	nav = *list;
	i = 1;
	while (nav->next && i < n)
	{
		prec = nav;
		nav = nav->next;
		i++;
	}
	prec->next = lst_new;
	lst_new->next = nav;
}
