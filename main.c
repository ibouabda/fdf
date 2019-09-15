/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:06:11 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/15 19:11:15 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		checkandparse(int argc, char **argv, int ***dbtab)
{
	int	fd;
	int	fd_dir;
	int size;

	if (argc != 4)
		ft_putendl("usage: ./fillit target_file weidth longer");
	fd_dir = open(argv[1], O_DIRECTORY);
	if ((fd = open(argv[1], O_RDONLY)) < 0 || fd_dir > 0)
	{
		ft_putendl("error");
		if (fd_dir > 0)
			close(fd_dir);
		ft_exit(NULL, NULL);
	}
	size = read_file(fd, dbtab);
	close(fd);
	return (size);
}

int		main(int argc, char **argv)
{
	int	**dbtab;
	int size;
	t_env e;

	size = checkandparse(argc, argv, &dbtab);
	create_img(ft_atoi(argv[2]), ft_atoi(argv[3]), &e);
	table_too_img(&e, dbtab, size);
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	mlx_loop(e.mlx_ptr);
	//ft_2dputtabint(dbtab, size);
	ft_2dmemdel((void**)dbtab);
	return (0);
}
