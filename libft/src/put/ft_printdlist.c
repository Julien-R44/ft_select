/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 00:33:15 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/14 13:01:23 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printdlist(t_dlist *list, char sep)
{
	t_dlist *tmp;

	tmp = list;
	while (tmp)
	{
		ft_putstr((char *)tmp->content);
		ft_putchar(sep);
		tmp = tmp->next;
	}
}
