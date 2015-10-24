/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:54:58 by jripoute          #+#    #+#             */
/*   Updated: 2015/01/29 03:49:03 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
