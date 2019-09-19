/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:29:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/19 11:49:34 by ibouabda         ###   ########.fr       */
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

void ft_draw_line(t_point p1, t_point p2, t_env *e)
{
	float eps;
	float m;

	eps = 0;
	if (p2.y - p1.y != 0)
		m = (p2.x - p1.x) / (p2.y - p1.y);
	else
		m = 0;
	while (p1.x <= p2.x)
	{
		ft_fill_pixel(p1, 255, e);
		if (eps + m < 0.5)
			eps = eps + m;
		else
		{
			p1.y = p1.y + 1;
			eps = eps + m - 1;
		}
		p1.x++;
	}
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