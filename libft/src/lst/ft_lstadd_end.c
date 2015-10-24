/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 01:26:55 by jripoute          #+#    #+#             */
/*   Updated: 2015/01/23 05:49:53 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *last_link;

	if (new && *alst)
	{
		last_link = *alst;
		while (last_link->next != NULL)
			last_link = last_link->next;
		last_link->next = new;
	}
	else if (new)
		*alst = new;
}
