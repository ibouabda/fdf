/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:50:30 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/19 23:21:02 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void highline(t_point a, t_point b, t_env *e)
{
	float x;
	float m;
	t_point point;

	if (a.y > b.y)
	{
		point = a;
		a = b;
		b = point;
	}
	x = a.x;
	m = (float)(b.x - a.x) / (float)(b.y - a.y);
	while (a.y <= b.y && a.x < e->winx && a.y < e->winy)
	{
		ft_fill_pixel(a, 255, e);
		x += m;
		a.x = (int)(x + 0.5);
		a.y++;
	}
}
void ft_line(t_point a, t_point b, t_env *e)
{
	float y;
	float m;

	m = (float)(b.y - a.y) / (float)(b.x - a.x);
	y = a.y;
	printf("m = %f \n", m);
	if (m <= 1.0 && m >= -1.0)
	{
		while (a.x <= b.x && a.x < e->winx && a.y < e->winy)
		{
			printf("y = %f, a.y = %i a.x = %i \n", y, a.y, a.x);
			ft_fill_pixel(a, 255, e);
			y += m;
			a.y = (int)(y + 0.5);
			a.x++;
		}
	}
	else
		highline(a, b, e);
}

void ft_vertical(t_point a, t_point b, t_env *e)
{
	while (a.y <= b.y && a.x < e->winx && a.y < e->winy)
	{
		ft_fill_pixel(a, 255, e);
		a.y++;
	}
}

void ft_drawline(t_point *a, t_point *b, t_env *e)
{
	t_point *point;

	printf("a.x = %i a.y = %i b.x = %i b.y = %i\n", a->x, a->y, b->x, b->y);
	if (a->x == b->x)
	{
		if (a->y > b->y)
		{
			point = a;
			a = b;
			b = point;
		}
		ft_vertical(*a, *b, e);
	}
	else
	{
		if (a->x > b->x)
		{
			point = a;
			a = b;
			b = point;
		}
		ft_line(*a, *b, e);
	}
}