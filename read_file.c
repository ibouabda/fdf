/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:55:25 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/11 18:17:49 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_check_line(t_list *m)
{
	int i;
	int var;
	char *line;

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

// int	**create_dbtable(t_list *m, int size)
// {
// 	int **dbint;
// 	int nbvar;

// 	nbvar = 0;
// 	dbint = ft_2dintnew(size);
// 	while (m)
// 	{
		
// 		m = m->next;
// 	}
// }

int	read_file(int fd)
{
	char	*line;
	t_list	*m;
	int		size;

	m = NULL;
	size = 1;
	while (get_next_line(fd, &line))
	{
		if (!line[0])
		{
			ft_lstdelstr(m);
			ft_strdel(&line);
			return (0);
		}
		ft_lstaddend(&m, ft_lstnewd(line, 0));
		size++;
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