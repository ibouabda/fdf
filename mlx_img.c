/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:29:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/20 12:56:18 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void ft_find_color(t_point a, t_env *e)
// {
// 	int color;
// 	char *str;

// 	color = 1000;
// 	str = ft_itoa_base(color, 16);
// 	ft_fill_pixel(a, ft_strjoin("0x", str), e);
// 	ft_strdel(&str);
	
// }

void ft_find_color(t_point a, t_env *e)
{
	ft_fill_pixel(a, a.h * 14, e);
	
}

void	ft_fill_pixel(t_point point, int color, t_env *e)
{
	int pos;

	pos = point.y * e->winx * 4 + point.x * 4;
	e->img_string[pos] = (char) 150;
	e->img_string[pos + 1] = (char) 0;
	e->img_string[pos + 2] = (char) color;
}

void	ft_fill_pixel_hexa(t_point point, char *color, t_env *e)
{
	int pos;

	pos = point.y * e->winx * 4 + point.x * 4;
	ft_strcpy(e->img_string + pos, color);
	ft_strcpy(e->img_string + pos + 1, color);
	ft_strcpy(e->img_string + pos + 2, color);
	ft_strdel(&color);
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