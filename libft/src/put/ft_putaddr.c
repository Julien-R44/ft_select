/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 22:03:26 by jripoute          #+#    #+#             */
/*   Updated: 2015/01/30 03:06:45 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putaddr(void *ptr)
{
	long int			base;
	char				tmp;
	unsigned long int	n;

	n = (unsigned long int)ptr;
	base = 16;
	write(1, "0x", 2);
	while (n / base >= 16)
		base *= 16;
	while (base > 0)
	{
		tmp = '0' + n / base;
		if (tmp > '9')
		{
			tmp += 39;
			write(1, &tmp, 1);
		}
		else
			write(1, &tmp, 1);
		n %= base;
		base /= 16;
	}
}
