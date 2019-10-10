/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:29:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/10/10 18:34:54 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_find_color(t_point a, t_env *e)
{
	int	color;

	color = 0;
	if (a.h > 0)
		color = ABS(255 * (a.h / (float)(e->max * e->alt)));
	if (a.h < 0)
		color = ABS(255 * (a.h / (float)(e->min * e->alt)));
	ft_fill_pixel(a, color, e);
}

void	ft_fill_pixel(t_point point, int color, t_env *e)
{
	int	pos;

	pos = point.y * e->winx * 4 + point.x * 4;
	if (point.h >= 0)
	{
		e->img_string[pos] = (char)150;
		e->img_string[pos + 1] = (char)0;
		e->img_string[pos + 2] = (char)color;
	}
	else
	{
		e->img_string[pos] = (char)150;
		e->img_string[pos + 1] = (char)color;
		e->img_string[pos + 2] = (char)0;
	}
}

void	new_window(t_env *e)
{
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, e->winx, e->winy, "fdf");
}

void	img(t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	e->img_ptr = mlx_new_image(e->mlx_ptr, e->winx, e->winy);
	e->img_string = mlx_get_data_addr(e->img_ptr, &(bpp), &(s_l), &(endian));
}

void	new_img(t_env *e)
{
	int		bpp;
	int		s_l;
	int		endian;

	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx_ptr, e->winx, e->winy);
	e->img_string = mlx_get_data_addr(e->img_ptr, &(bpp), &(s_l), &(endian));
}
