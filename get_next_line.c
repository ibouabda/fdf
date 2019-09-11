/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:44:09 by retounsi          #+#    #+#             */
/*   Updated: 2019/07/08 11:02:03 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line(char *str)
{
	size_t size;

	size = 0;
	while (str[size] != '\n' && str[size])
	{
		size++;
	}
	return (size);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buf;
	char			*tmp;
	char			*todel;
	int				red;

	buf = !buf ? ft_strnew(BUFF_SIZE) : buf;
	tmp = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(tmp, '\n') && (red = read(fd, tmp, BUFF_SIZE)))
	{
		if (red == -1)
			return (-1);
		todel = buf;
		tmp[red] = '\0';
		buf = ft_strjoin(buf, tmp);
		ft_strdel(&todel);
	}
	ft_strdel(&tmp);
	*line = ft_strsub(buf, 0, ft_line(buf));
	if ((red || *buf) && (tmp = buf))
	{
		buf = ft_strsub(buf, ft_line(buf) + 1, ft_strlen(buf) - ft_line(buf));
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}
