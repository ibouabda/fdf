/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:06:11 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/27 12:22:04 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void zoom(int keycode, t_env *e)
{
	t_point a;
	t_point b;
	t_point a2;
	t_point b2;

	a = interpret(0, 0, e->dbtab[0][0], e);
	b = interpret(e->size - 1, e->sizey - 1, 0, e);
	if (keycode == THREE)
		e->zoom += 5;
	if (keycode == TWO)
		e->zoom -= 5;
	a2 = interpret(0, 0, e->dbtab[0][0], e);
	b2 = interpret(e->size - 1, e->sizey - 1, 0, e);
	e->posx = e->posx - ((b2.x - a2.x) - (b.x - a.x)) / 2;
	e->posy = e->posy - ((b2.y - a2.y) - (b.y - a.y)) / 2;
}

void ft_maxmin(t_env *e)
{
	int taby;
	int tabx;

	taby = 0;
	e->max = 0;
	e->min = 0;

	while (e->dbtab[taby])
	{
		tabx = 0;
		while (tabx < e->size)
		{
			if (e->dbtab[taby][tabx] > e->max)
				e->max = e->dbtab[taby][tabx];
			if (e->dbtab[taby][tabx] < e->min)
				e->min = e->dbtab[taby][tabx];
			tabx++;
		}
		taby++;
	}
	if (e->min >= 0)
		e->min = e->max;
	if (e->max <= 0)
		e->max = e->min;
	e->sizey = taby;
}

int checkandparse(int argc, char *argv, int ***dbtab)
{
	int fd;
	int fd_dir;
	int size;

	if (argc != 4)
	{
		ft_putendl("usage: ./fillit target_file [weidth_size long_size]");
		exit(1);
	}
	fd_dir = open(argv, O_DIRECTORY);
	if ((fd = open(argv, O_RDONLY)) < 0 || fd_dir > 0)
	{
		if (fd_dir > 0)
			close(fd_dir);
		ft_exit(1, NULL, NULL);
	}
	size = read_file(fd, dbtab);
	close(fd);
	return (size);
}

void begin(t_env *e)
{
	t_point a;
	t_point b;

	e->angx = 0;
	e->angy = 0;
	e->zoom = 15;
	e->posx = 0;
	e->posy = 0;
	e->alt = 1;
	ft_maxmin(e);
	a = interpret(0, 0, e->dbtab[0][0], e);
	b = interpret((e->size - 1), (e->sizey - 1), e->dbtab[e->sizey - 1][e->size - 1], e);
	e->posx = (e->winx / 2 - (b.x - a.x) / 2);
	e->posy = (e->winy / 2 - (b.y - a.y) / 2);
}

void begin_inter(t_env *e)
{
	t_point a;
	t_point b;

	e->angx = 0;
	e->angy = 0;
	e->zoom = 18;
	e->posx = 0;
	e->posy = 0;
	e->bool = 0;
	e->alt = 1;
	ft_maxmin(e);
	a = interpret(0, 0, e->dbtab[0][0], e);
	b = interpret((e->size - 1), (e->sizey - 1), e->dbtab[e->sizey - 1][e->size - 1], e);
	e->posx = (e->winx / 2 - (b.x - a.x) / 2);
	e->posy = (e->winy / 4.5 - (b.y - a.y) / 2);
}

int ft_key_hook(int keycode, t_env *e)
{
	if (e->bool == 0)
	{
		if (keycode == ENTER)
			e->bool = 1;
		if (keycode == ESC)
		{
			mlx_destroy_image(e->mlx_ptr, e->esc_img_ptr);
			mlx_destroy_image(e->mlx_ptr, e->img_ptr);
			ft_exit(0, e->dbtab, NULL);
		}
	}
	if (e->bool == 1)
	{
		if (keycode == R)
			begin(e);
		if (keycode == P)
		{
			e->proj == 0 ? e->proj++ : e->proj--;
			begin(e);
		}
		if (keycode == ESC)
		{
			e->bool = 0;
			mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->esc_img_ptr, 0, 0);
			interface(e);
		}
		if (keycode == THREE || (keycode == TWO && e->zoom > 5))
			zoom(keycode, e);
		if (keycode == Q && ((e->proj == 0) || e->max < 0
		|| (e->proj == 1 && e->max * (e->alt + 4) < 1000)))
			e->alt += 4;
		if (keycode == E && ((e->proj == 0) || e->min > 0
		|| (e->proj == 1 && e->min * (e->alt - 4) < 1000)))
			e->alt -= 4;   
		if (keycode == UP_ARROW)
			e->posy -= 10;
		if (keycode == DOWN_ARROW)
			e->posy += 10;
		if (keycode == RIGHT_ARROW)
			e->posx += 10;
		if (keycode == LEFT_ARROW)
			e->posx -= 10;
		if (keycode == W)
			e->angy -= 10;
		if (keycode == S)
			e->angy += 10;
		if (keycode == D)
			e->angx += 10;
		if (keycode == A)
			e->angx -= 10;
		if (e->bool == 1)
		{
			new_img(e);
			table_too_img(e);
			mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
		}
	}
	printf("e->alt : %i\ne->min : %i\n", e->alt, e->min);
	return (0);
}

int main(int argc, char **argv)
{
	t_env e;

	e.proj = 0;
	e.size = checkandparse(argc, "maps/42.fdf", &e.dbtab);
	new_window(ft_atoi(argv[2]), ft_atoi(argv[3]), &e);
	begin_inter(&e);
	img(&e);
	table_too_img(&e);
	e.esc_img_ptr = e.img_ptr;
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.esc_img_ptr, 0, 0);
	interface(&e);
	ft_2dmemdel((void **)e.dbtab);
	img(&e);
	e.size = checkandparse(argc, argv[1], &e.dbtab);
	ft_2dputtabint(e.dbtab, e.size);
	begin(&e);
	mlx_hook(e.win_ptr, 2, (1 << 0), ft_key_hook, &e);
	mlx_loop(e.mlx_ptr);
	ft_2dmemdel((void **)e.dbtab); // a enlever ?
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
// table_too_img(&e);
// printf("winx : %i, winy : %i\n", e.winx, e.winy);
// printf("e.posx : %i e.posy : %i\n", e.posx, e.posy);