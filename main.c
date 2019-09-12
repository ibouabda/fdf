/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:06:11 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/12 17:24:17 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int	fd;
	int	fd_dir;
	int	**dbtab;
	int size;

	(void)argc;
	fd_dir = open(argv[1], O_DIRECTORY);
	if ((fd = open(argv[1], O_RDONLY)) < 0 || fd_dir > 0)
	{
		ft_putendl("error");
		close(fd_dir);
		return (-1);
	}
	size = read_file(fd, &dbtab);
	ft_2dputtabint(dbtab, size);
	ft_2dmemdel((void**)dbtab);
	close(fd);
	return (0);
}
