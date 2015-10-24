/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:28:41 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/14 17:03:29 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *list)
{
	t_list	*nav;
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
