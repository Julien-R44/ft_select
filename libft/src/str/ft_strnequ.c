/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:53:10 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/11 03:35:32 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		ret;

	if (!s1 || !s2)
		return (0);
	ret = ft_strncmp(s1, s2, n);
	if (ret == 0)
		return (1);
	return (0);
}
