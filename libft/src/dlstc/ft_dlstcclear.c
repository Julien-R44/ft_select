/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:40:06 by so                #+#    #+#             */
/*   Updated: 2015/03/07 17:40:13 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstcclear(t_dlist *list)
{
	t_dlist *nav;
	t_dlist	*tmp;

	nav = list->next;
	while (nav != list)
	{
		tmp = nav->next;
		free(nav);
		nav = tmp;
	}
}
