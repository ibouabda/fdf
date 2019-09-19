/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:29:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/19 19:35:49 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(t_point point, int color, t_env *e)
{
	int pos;

	pos = point.y * e->winx * 4 + point.x * 4;
	e->img_string[pos] = (char)color;
	e->img_string[pos + 1] = (char)color;
	e->img_string[pos + 2] = (char)color;
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
}

	// while (y < 720 && x < 1280 )
	// {
	// 	fill_pixel(e.img_string, x, y, 255);
	// 	x += 1;
	// 	y += 1;
	// }
	// mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	//mlx_hook(e.win_ptr, 2, (1 << 0), mlx_put_image_to_window, &e);