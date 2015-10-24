/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:38:56 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/12 19:07:22 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*yolo;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		yolo = (char*)ft_memalloc(ft_strlen(s) + 1);
		if (!yolo)
			return (NULL);
		while (s[i] != '\0')
		{
			yolo[i] = (*f)(s[i]);
			i++;
		}
		return (yolo);
	}
	return (0);
}
