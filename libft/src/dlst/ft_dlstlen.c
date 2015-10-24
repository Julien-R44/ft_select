/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:31:41 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/14 17:02:04 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlstlen(t_dlist *list)
{
	t_dlist	*nav;
	int		i;

	i = 0;
	nav = list;
	while (nav)
	{
		i++;
		nav = nav->next;
	}
	return (i);
}
