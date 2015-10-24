/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so <so@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:36:43 by so                #+#    #+#             */
/*   Updated: 2015/03/07 17:38:23 by so               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist *ft_dlstcnew(void const *content, size_t content_size)
{
	t_dlist		*dlst;
	void		*content_cpy;

	content_cpy = NULL;
	if (!content)
		content_size = 0;
	else
	{
		content_cpy = ft_memalloc(content_size);
		content_cpy = ft_memcpy(content_cpy, content, content_size);
	}
	dlst = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	if (dlst)
	{
		dlst->content = content_cpy;
		dlst->content_size = content_size;
		dlst->next = dlst;
		dlst->before = dlst;
		return (dlst);
	}
	return (NULL);
}
