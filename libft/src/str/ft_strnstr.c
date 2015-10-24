/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:04:50 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/17 16:04:53 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2 || !s2[0])
		return ((char *)s1);
	while (s1[j] != '\0' && j < n)
	{
		i = 0;
		while (s2[i] == s1[j + i] && j + i < n && s2[i] != '\0'
				&& s1[j + i] != '\0')
			i++;
		if (s2[i] == '\0')
			return ((char *)s1 + j);
		j++;
	}
	return (0);
}
