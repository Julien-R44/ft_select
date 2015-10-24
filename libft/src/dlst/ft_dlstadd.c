/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 23:01:22 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/17 14:53:17 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (new && *alst)
	{
		(*alst)->before = new;
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = new;
}
