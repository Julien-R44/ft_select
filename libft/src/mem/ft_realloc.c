/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 05:14:03 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/17 18:11:16 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void	*danew;

	danew = ft_memalloc(size);
	if (!danew || size == 0 || !ptr)
	{
		ft_memdel(ptr);
		return (NULL);
	}
	ft_memcpy(danew, ptr, old);
	free(ptr);
	ptr = danew;
	return (danew);
}
