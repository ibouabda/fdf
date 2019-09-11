/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:55:25 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/10 14:00:09 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(int fd, char **map)
{
	int		i;
	char	*line;
	int		**tab;

	i = 0;
	while (get_next_line(fd, &line))
		map[i++] = ft_strdup(line);
	while (map[i])
	{
		ft_strsplit(map[i], ' ');
	}
}
//a faire : stocker resultat de split dans un char ** et faire atoi pour chaque char* pour
//les stocker dans le tableau d'int **tab