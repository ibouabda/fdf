/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:29:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/10 13:33:13 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

void	fill_pixel(t_env *e, int x, int y, int color);
{
	e->img_string =
}

int		main()
{
	t_env	e;
	int		bpp;
	int		s_l;
	int		endian;

	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, 1280, 720,"test");
	e.img_ptr = mlx_new_image(e.mlx_ptr, 1280, 720);
	e.img_string = mlx_get_data_addr(e.img_ptr, &(bpp), &(s_l), &(endian));
	mlx_hook(e.win_ptr, 2, (1 << 0), mlx_put_image_to_window, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
