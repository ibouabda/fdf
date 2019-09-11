/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:55:25 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/11 17:08:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_check_line(t_list *m)
{
	int i;
	int k;
	int var;
	char *line;

	k = 0;
	while (m)
	{
		i = 0;
		line = (char*)m->content;
		while(line[i])
		{
			if (line[i] == '-')
				i++;
			if (!ft_isdigit(line[i]))
				return (0);
			var = i;
			while (ft_isdigit(line[i]))
				i++;
			if (line[i] == ' ' && i - var < 5)
				i++;
			else if (line[i] || i - var >= 5)
				return (0);
		}
		m = m->next;
	}
	return (1);
}

int	read_file(int fd)
{
	char	*line;
	t_list	*m;

	m = NULL;
	while (get_next_line(fd, &line))
	{
		if (!line[0])
		{
			ft_lstdelstr(m);
			ft_strdel(&line);
			return (0);
		}
		ft_lstaddend(&m, ft_lstnewd(line, 0));
	}
	ft_putstrlst(m);
	if (!m || !((char*)m->content)[0] || !ft_check_line(m))
	{
		ft_lstdelstr(m);
		return (0);
	}
	ft_lstdelstr(m);
	return (1);
}