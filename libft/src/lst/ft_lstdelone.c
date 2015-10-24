/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 05:04:02 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/21 11:24:13 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		default_deleter(void *data, size_t size)
{
	(void)size;
	ft_memdel(&data);
}

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (del == NULL)
		del = default_deleter;
	if (alst && *alst)
	{
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
