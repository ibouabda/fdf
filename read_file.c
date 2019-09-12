/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:55:25 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/12 17:25:14 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_analyze_line(char *line)
{
	int	i;
	int	var;
	int	nbvar;

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

int		ft_check_line(t_list *m)
{
	int	nbvarmem;
	int	nbvar;

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

int		*ft_insert_nb(char *str, int nbvar)
{
	int	*tab;
	int	i;
	int	k;

	i = 0;
	k = 0;
	tab = ft_intnew(nbvar);
	while (str[i])
	{
		tab[k] = ft_atoi(str + i);
		while (str[i] && str[i] != ' ')
			i++;
		if (str[i] == ' ')
			i++;
		k++;
	}
	return (tab);
}

int		**create_dbtable(t_list *m, int size, int nbvar)
{
	int	**dbint;
	int	y;

	dbint = ft_2dintnew(size);
	y = 0;
	while (m)
	{
		dbint[y] = ft_insert_nb((char*)m->content, nbvar);
		m = m->next;
		y++;
	}
	return (dbint);
}

int		read_file(int fd, int ***dbtab)
{
	char	*line;
	t_list	*m;
	int		size;
	int		nbvar;

	m = NULL;
	size = 0;
	nbvar = 0;
	*dbtab = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstaddend(&m, ft_lstnewd(line, 0));
		if (!line[0])
			ft_exit(*dbtab, m);
		size++;
	}
	if (line[0])
		ft_exit(*dbtab, m);
	ft_strdel(&line);
	if (!m || !((char *)m->content)[0] || (nbvar = ft_check_line(m)) == 0)
		ft_exit(*dbtab, m);
	*dbtab = create_dbtable(m, size, nbvar);
	ft_lstdelstr(m);
	return (nbvar);
}
