/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 11:35:59 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/07 12:04:36 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# include "libft/libft.h"

typedef	struct		s_prlist
{
	char			*content;
	int				fd;
	struct s_prlist	*next;
	struct s_prlist	*prev;
}					t_prlist;

int					get_next_line(const int fd, char **line);

#endif
