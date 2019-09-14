/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:29:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/14 12:47:51 by retounsi         ###   ########.fr       */
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

int		main()
{
	t_env	e;
	int		bpp;
	int		s_l;
	int		endian;
	size_t	i;
	int		**tab;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, 1280, 720,"test");
	e.img_ptr = mlx_new_image(e.mlx_ptr, 1280, 720);
	e.img_string = mlx_get_data_addr(e.img_ptr, &(bpp), &(s_l), &(endian));
	while (y < 720 && x < 1280 )
	{
		fill_pixel(e.img_string, x, y, 255);
		x += 1;
		y += 1;
	}
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	//mlx_hook(e.win_ptr, 2, (1 << 0), mlx_put_image_to_window, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
