/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:38:56 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/17 16:07:51 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int i;
	int mem;

	i = 0;
	mem = -1;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			mem = i;
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char*)&s[i]);
	if (mem != -1)
		return ((char *)&s[mem]);
	return (NULL);
}
