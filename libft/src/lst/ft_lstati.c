/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstati.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:36:19 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/14 17:03:01 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstati(t_list *list, unsigned int i)
{
	t_list *nav;

	nav = list;
	while (nav && (i - 1))
	{
		i--;
		nav = nav->next;
	}
	return (nav);
}
