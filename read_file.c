/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:55:25 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/12 10:30:29 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_analyze_line(char *line)
{
	int i;
	int var;
	int nbvar;

	i = 0;
	nbvar = 0;
	while (line[i])
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
		nbvar++;
	}
	return (nbvar);
}

int ft_check_line(t_list *m)
{
	int nbvarmem;
	int nbvar;
	
	nbvarmem = -1;
	while (m)
	{
		if ((nbvar = ft_analyze_line((char *)m->content)) == 0)
			return (0);
		if (nbvarmem == -1)
			nbvarmem = nbvar;
		else if (nbvarmem != nbvar)
			return (0);
		m = m->next;
	}
	return (nbvar);
}

int *ft_insert_nb(t_list *m, int nbvar)
{
	char *str;
	int	*tab;
	int i;
	int k;

	i = 0;
	k = 0;
	str = m->content;
	tab = ft_intnew(nbvar);
	while (str[i])
	{
		tab[k] = ft_atoi(str + i);
		while(str[i] && str[i] != ' ')
			i++;
		if (tab[i])
			i++;
		k++;
	}
	return (tab);
}

int **create_dbtable(t_list *m, int size, int nbvar)
{
	int **dbint;
	int y;

	dbint = ft_2dintnew(size);
	y = 0;
	while (m)
	{
		dbint[y] = ft_insert_nb(m, nbvar);
		m = m->next;
		y++;
	}
	return (dbint);
}

int **read_file(int fd)
{
	char *line;
	t_list *m;
	int size;
	int **dbtab;
	int nbvar;

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
	if (!m || !((char *)m->content)[0] || 0 == (nbvar = ft_check_line(m)))
	{
		ft_lstdelstr(m);
		return (0);
	}
	dbtab = create_dbtable(m, size, nbvar);
	ft_lstdelstr(m);
	return (dbtab);
}