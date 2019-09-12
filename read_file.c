/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:55:25 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/12 12:26:22 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_analyze_line(char *line)
{
	int i;
	int var;
	int nbvar;

	i = 0;
	nbvar = 1;
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
	
	nbvarmem = 0;
	while (m)
	{
		if ((nbvar = ft_analyze_line((char *)m->content)) == 0)
			return (0);
		printf("nbvar : %i\n", nbvar);
		if (nbvarmem == 0)
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
	str = (char*)m->content;
	tab = ft_intnew(nbvar);
	while (str[i] && k < nbvar)
	{
		tab[k] = ft_atoi(str + i);
		while(str[i] && str[i] != ' ')
			i++;
		while(str[i] == ' ')
			i++;
		k++;
	}
	//ft_puttabint(tab, nbvar);
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

int **read_file(int fd) //ajouter verifier derniere ligne
{
	char *line;
	t_list *m;
	int size;
	int **dbtab;
	int nbvar;

	m = NULL;
	size = 1;
	nbvar = 0;
	while (get_next_line(fd, &line))
	{
		if (!line[0])
		{
			ft_lstdelstr(m);
			ft_strdel(&line);
			return (NULL);
		}
		ft_lstaddend(&m, ft_lstnewd(line, 0));
		size++;
	}
	ft_putstrlst(m);
	if (!m || !((char *)m->content)[0] || (nbvar = ft_check_line(m)) == 0) 
	{
		ft_lstdelstr(m);
		return (NULL);
	}
	ft_putendl("ok");
	dbtab = create_dbtable(m, size, nbvar); //probleme avec le size/nbvar du tab
	ft_lstdelstr(m);
	ft_2dputtabint(dbtab, nbvar);
	return (dbtab);
}