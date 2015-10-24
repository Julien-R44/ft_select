/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 23:13:50 by y0ja              #+#    #+#             */
/*   Updated: 2014/12/05 03:32:39 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

int		end_del(char *buf);
int		get_next_line(int const fd, char **line);
int		create_and_cut_da_line(char **str, char *slash, char **line, char *buf);

#endif
