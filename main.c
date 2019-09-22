/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:06:11 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/22 20:47:01 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int checkandparse(int argc, char **argv, int ***dbtab)
{
	int fd;
	int fd_dir;
	int size;

	if (argc != 4)
	{
		ft_putendl("usage: ./fillit target_file [weidth_size long_size]");
		exit(1);
	}
	fd_dir = open(argv[1], O_DIRECTORY);
	if ((fd = open(argv[1], O_RDONLY)) < 0 || fd_dir > 0)
	{
		if (fd_dir > 0)
			close(fd_dir);
		ft_exit(1, NULL, NULL);
	}
	size = read_file(fd, dbtab);
	close(fd);
	return (size);
}

int ft_key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
		ft_exit(0, e->dbtab, NULL);
	if (keycode == W)
		e->zoom += 5;
	if (keycode == S && e->zoom > 5)
		e->zoom -= 5;
	if (keycode == F)
		e->alt += 5;
	if (keycode == D)
		e->alt -= 5;
	if (keycode == UP_ARROW)
		e->posy -= 10;
	if (keycode == DOWN_ARROW)
		e->posy += 10;
	if (keycode == RIGHT_ARROW)
		e->posx += 10;
	if (keycode == LEFT_ARROW)
		e->posx -= 10;
	new_img(e);
	table_too_img(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	return (0);
}

void ft_maxmin(t_env *e)
{
	int taby;
	int tabx;

	taby = 0;
	tabx = 0;

	while (e->dbtab[taby])
	{
		while (tabx < e->size)
		{
			if (e->dbtab[taby][tabx] > e->max)
				e->max = e->dbtab[taby][tabx];
			if (e->dbtab[taby][tabx] < e->min)
				e->min = e->dbtab[taby][tabx];
			tabx++;
		}
		tabx = 0;
		taby++;
	}
	if (e->min >= 0)
		e->min = e->max;
	if (e->max <= 0)
		e->max = e->min;
}

int main(int argc, char **argv)
{
	t_env e;

	e.zoom = 20;
	e.alt = 1;
	e.size = checkandparse(argc, argv, &e.dbtab);
	new_window(ft_atoi(argv[2]), ft_atoi(argv[3]), &e);
	e.posx = e.winx / 3;
	e.posy = e.winy / 3;
	printf("posx : %i, posy : %i\n", e.posx, e.posy);
	img(&e);
	ft_maxmin(&e);
	table_too_img(&e);
	printf("winx : %i, winy : %i\n", e.winx, e.winy);
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	mlx_hook(e.win_ptr, 2, (1 << 0), ft_key_hook, &e);
	mlx_loop(e.mlx_ptr);
	ft_2dmemdel((void **)e.dbtab);
	return (0);
}
// t_point a;
// t_point b;
// a.x = 580;
// a.y = 300;
// b.x = 600;
// b.y = 250;
// ft_trylines(&a, &b, &e);
// ft_fill_pixel(a, 255, &e);
// ft_fill_pixel(b, 255, &e);
// table_too_img(&e, dbtab, size);