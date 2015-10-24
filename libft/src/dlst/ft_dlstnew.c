/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 22:59:16 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/14 13:00:47 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
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
		dlst->next = NULL;
		dlst->before = NULL;
		return (dlst);
	}
	return (NULL);
}
