/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstati.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 21:15:29 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/17 14:53:44 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstati(t_dlist *list, unsigned int i)
{
	t_dlist *nav;

	nav = list;
	while (nav->next && (i - 1))
	{
		i--;
		nav = nav->next;
	}
	return (nav);
}
