/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:39:33 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/17 18:12:51 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	tmp[n];
	char	*pdest;
	char	*psrc;
	size_t	i;

	i = 0;
	pdest = (char *)dest;
	psrc = (char *)src;
	if (n == 0)
		return (0);
	while (i < n)
	{
		tmp[i] = psrc[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		pdest[i] = tmp[i];
		i++;
	}
	return (pdest);
}
