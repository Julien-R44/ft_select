/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 22:35:26 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/08 22:42:06 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsdup(const wchar_t *s1)
{
	wchar_t *str;

	str = (wchar_t *)malloc(sizeof(wchar_t) * (ft_wcslen(s1) + 1));
	if (str == NULL)
		return (str);
	ft_wcscpy(str, s1);
	return (str);
}
