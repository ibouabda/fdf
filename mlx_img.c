/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:29:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/15 14:13:16 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

void	fill_pixel(char *img_string, int x, int y, int color)
{
	int pos;
	int	pos_y;
	int	pos_x;

	pos = y * 1280 * 4 + x * 4;
	img_string[pos] = (char)color;
	img_string[pos + 1] = (char)color;
	img_string[pos + 2] = (char)color;
}

void	create_img(int winx, int winy, t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	e->winx = winx;
	e->winy = winy;
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, winx, winy,"test");
	e->img_ptr = mlx_new_image(e->mlx_ptr, winx, winy);
	e->img_string = mlx_get_data_addr(e->img_ptr, &(bpp), &(s_l), &(endian));
	mlx_loop(e->mlx_ptr);
}

	// while (y < 720 && x < 1280 )
	// {
	// 	fill_pixel(e.img_string, x, y, 255);
	// 	x += 1;
	// 	y += 1;
	// }
	// mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	//mlx_hook(e.win_ptr, 2, (1 << 0), mlx_put_image_to_window, &e);