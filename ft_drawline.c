/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:50:30 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/22 12:57:58 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void highline(t_point a, t_point b, t_env *e)
{
	float x;
	float m;
	float h;
	float mh;
	t_point point;

	if (a.y > b.y)
	{
		point = a;
		a = b;
		b = point;
	}
	x = a.x;
	m = (float)(b.x - a.x) / (float)(b.y - a.y);
	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	while (a.y <= b.y && a.x < e->winx && a.y < e->winy)
	{
		ft_find_color(a, e);
		x += m;
		a.x = (int)(x + 0.5);
		a.y++;
		h += mh;
		a.h = (int)(h + 0.5);
	}
}
void ft_line(t_point a, t_point b, t_env *e)
{
	float y;
	float m;
	float mh;
	float h;

	m = (float)(b.y - a.y) / (float)(b.x - a.x);
	y = a.y;
	h = a.h;
	// printf("m = %f \n", m);
	if (m <= 1.0 && m >= -1.0)
	{
		mh = (float)(b.h - a.h) / (float)(b.x - a.x);
		while (a.x <= b.x && a.x < e->winx && a.y < e->winy)
		{
			// printf("y = %f, a.y = %i a.x = %i \n", y, a.y, a.x);
			ft_find_color(a, e);
			y += m;
			h += mh;
			a.y = (int)(y + 0.5);
			a.h = (int)(h + 0.5);
			a.x++;
		}
	}
	else
		highline(a, b, e);
}

void ft_vertical(t_point a, t_point b, t_env *e)
{
	float h;
	float mh;
	
	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	while (a.y <= b.y && a.x < e->winx && a.y < e->winy)
	{
		ft_find_color(a, e);
		a.y++;
		h += mh;
		a.h = (int)(h + 0.5);
	}
}

void ft_horizontal(t_point a, t_point b, t_env *e)
{
	float h;
	float mh;
	
	mh = (float)(b.h - a.h) / (float)(b.x - a.x);
	h = a.h;
	while (a.x <= b.x && a.x < e->winx && a.y < e->winy)
	{
		ft_find_color(a, e);
		a.x++;
		h += mh;
		a.h = (int)(h + 0.5);
	}
}

void ft_drawline(t_point *a, t_point *b, t_env *e) //horizontal a ajouter
{
	t_point *point;

	// printf("a.x = %i a.y = %i b.x = %i b.y = %i\n", a->x, a->y, b->x, b->y);
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
		if (a->y == b->y)
			ft_horizontal(*a, *b, e);
		else
			ft_line(*a, *b, e);
	}
}