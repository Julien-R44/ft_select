/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:47:17 by so                #+#    #+#             */
/*   Updated: 2015/03/07 17:47:23 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstcpush(t_dlist *node, t_dlist *new)
{
	if (node && new)
	{
		new->before = node;
		new->next = node->next;
		node->next->before = new;
		node->next = new;
	}
}
