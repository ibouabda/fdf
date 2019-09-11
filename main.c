/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:06:11 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/10 13:33:12 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	size_t	nb_line;
	char	*line;
	int		fd;
	char	**map;

	nb_line = 0;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line))
		nb_line++;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = ft_2dstrnew(nb_line);
	read_file(fd , map);
	return (0);
}
