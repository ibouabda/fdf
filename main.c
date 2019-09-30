/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:06:11 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/30 12:31:55 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_maxmin(t_env *e)
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

int		checkandparse(char *argv, int ***dbtab)
{
	int fd;
	int fd_dir;
	int size;

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

void	begin_inter(t_env *e)
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
	b = interpret((e->size - 1), (e->sizey - 1),\
	e->dbtab[e->sizey - 1][e->size - 1], e);
	e->posx = (e->winx / 2 - (b.x - a.x) / 2);
	e->posy = (e->winy / 4.5 - (b.y - a.y) / 2);
}

void	ft_verifscreensize(t_env *e, int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putendl(USAGE);
		exit(1);
	}
	e->winx = ft_atoi(argv[2]);
	e->winy = ft_atoi(argv[3]);
	if (e->winx < 400 || e->winy < 800 || e->winx > 2560 || e->winy > 1440)
	{
		ft_putendl(USAGE);
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	t_env e;

	e.proj = 0;
	ft_verifscreensize(&e, argc, argv);
	e.size = checkandparse("maps/42.fdf", &e.dbtab);
	new_window(&e);
	begin_inter(&e);
	img(&e);
	table_too_img(&e);
	e.esc_img_ptr = e.img_ptr;
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.esc_img_ptr, 0, 0);
	interface(&e);
	ft_2dmemdel((void **)e.dbtab);
	img(&e);
	e.size = checkandparse(argv[1], &e.dbtab);
	begin(&e);
	mlx_hook(e.win_ptr, 2, (1 << 0), ft_key_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
