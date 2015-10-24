/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 22:59:01 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/08 23:00:08 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ullintlen(unsigned long long nb)
{
	int		len;

	len = 1;
	while (nb >= 10 && len++)
		nb = nb / 10;
	return (len);
}

static char		*convert_ullint(char *str, unsigned long long nb)
{
	if (nb >= 10)
	{
		str = convert_ullint(str, (nb / 10));
		str[ft_strlen(str)] = (char)((nb % 10) + '0');
		return (str);
	}
	str[ft_strlen(str)] = (char)(nb + '0');
	return (str);
}

char			*ft_ullitoa(unsigned long long nb)
{
	char *str;

	str = (char *)ft_memalloc(sizeof(char) * ft_ullintlen(nb) + 1);
	if (!str)
		return (NULL);
	return (convert_ullint(str, nb));
}
