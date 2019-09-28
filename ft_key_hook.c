/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:20:12 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/28 15:12:37 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	begin(t_env *e)
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
	b = interpret((e->size - 1), (e->sizey - 1),\
	e->dbtab[e->sizey - 1][e->size - 1], e);
	e->posx = (e->winx / 2 - (b.x - a.x) / 2);
	e->posy = (e->winy / 2 - (b.y - a.y) / 2);
}

void	zoom(int keycode, t_env *e)
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

void	ft_key_hook3(int keycode, t_env *e)
{
	if (keycode == THREE || (keycode == TWO && e->zoom > 5))
		zoom(keycode, e);
	if (keycode == Q && ((e->proj == 0) || e->max < 0
	|| (e->proj == 1 && e->max * (e->alt + 8) < 1000)))
		e->alt += 4;
	if (keycode == E && ((e->proj == 0) || e->min > 0
	|| (e->proj == 1 && e->min * (e->alt - 8) < 1000)))
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
		e->angx += 100;
	if (keycode == A)
		e->angx -= 100;
}

void	ft_key_hook2(int keycode, t_env *e)
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
}

int		ft_key_hook(int keycode, t_env *e)
{
	if (e->bool == 0)
	{
		e->bool = keycode == ENTER ? 1 : 0;
		if (keycode == ESC)
		{
			mlx_destroy_image(e->mlx_ptr, e->esc_img_ptr);
			mlx_destroy_image(e->mlx_ptr, e->img_ptr);
			ft_exit(0, e->dbtab, NULL);
		}
	}
	if (e->bool == 1)
	{
		ft_key_hook2(keycode, e);
		ft_key_hook3(keycode, e);
		if (e->bool == 1)
		{
			new_img(e);
			table_too_img(e);
			mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
		}
	}
	return (0);
}
