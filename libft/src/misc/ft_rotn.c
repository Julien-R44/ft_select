/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 14:23:20 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/17 18:12:27 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	da_rot(char *c, int n)
{
	int j;

	j = 0;
	while (j < n)
	{
		if (*c == 'Z')
			*c = '@';
		if (*c == 'z')
			*c = '`';
		*c += 1;
		j++;
	}
}

char		*ft_rotn(char const *str, int n)
{
	char	*roted;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (n > 25)
		n = 25;
	roted = ft_strdup(str);
	while (roted[i])
	{
		if (ft_isalpha(roted[i]))
			da_rot(&roted[i], n);
		i++;
	}
	return (roted);
}
