/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:59:16 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/17 15:58:24 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c1;
	char	*c2;

	if (n == 0 || dst == src)
		return (dst);
	c1 = (char *)dst;
	c2 = (char *)src;
	while (--n)
		*c1++ = *c2++;
	*c1 = *c2;
	return (dst);
}
