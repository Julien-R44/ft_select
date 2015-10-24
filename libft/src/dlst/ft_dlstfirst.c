/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 21:16:08 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/22 21:55:53 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstfirst(t_dlist *list)
{
	t_dlist *last;

	last = list;
	if (list == NULL)
		return (NULL);
	if (list->before == NULL)
		return (list);
	while (last->before)
		last = last->before;
	return (last);
}
