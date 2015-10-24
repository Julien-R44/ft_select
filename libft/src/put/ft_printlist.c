/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 01:37:34 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/07 11:14:01 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlist(t_list *list, char sep)
{
	while (list != NULL)
	{
		ft_putstr((char *)list->content);
		ft_putchar(sep);
		list = list->next;
	}
}
