/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:00:07 by jripoute          #+#    #+#             */
/*   Updated: 2015/01/22 02:32:59 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_nb_wordz(char const *s, char c)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && ((s[i] == c && s[i + j] == c)
			|| (s[i] != c && s[i + j] != c)))
			j++;
		if (s[i] != c)
			n++;
		i = i + j;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (get_nb_wordz(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		j = 0;
		while (s[i + j] && ((s[i] == c && s[i + j] == c)
			|| (s[i] != c && s[i + j] != c)))
			j++;
		if (s[i] != c)
			if (!(res[k++] = ft_strsub(s, i, j)))
				return (NULL);
		i = i + j;
	}
	res[k] = NULL;
	return (res);
}
