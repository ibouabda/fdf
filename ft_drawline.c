/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:50:30 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/23 13:18:52 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void highline(t_point a, t_point b, t_env *e, float m)
{
	float x;
	float h;
	float mh;

	x = a.x;
	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	// printf("highline\n");
	while (a.y <= b.y && a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
	{
		ft_find_color(a, e);
		x += m;
		a.x = (int)(x + 0.5);
		a.y++;
		h += mh;
		a.h = (int)(h + 0.5);
	}
}

void highline2(t_point a, t_point b, t_env *e, float m)
{
	float x;
	float h;
	float mh;

	x = a.x;
	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	// printf("highline2\n");
	while (a.y >= b.y && a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
	{
		ft_find_color(a, e);
		x -= m;
		a.x = (int)(x + 0.5);
		a.y--;
		h -= mh;
		a.h = (int)(h + 0.5);
	}
}

void ft_line(t_point a, t_point b, t_env *e, float m)
{
	float y;
	float mh;
	float h;

	m = (float)(b.y - a.y) / (float)(b.x - a.x);
	y = a.y;
	h = a.h;
	// printf("line\n");
	// printf("m = %f \n", m);
	if (m <= 1.0 && m >= -1.0)
	{
		mh = (float)(b.h - a.h) / (float)(b.x - a.x);
		while (a.x <= b.x && a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
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
}

void ft_line2(t_point a, t_point b, t_env *e, float m)
{
	float y;
	float mh;
	float h;


	y = a.y;
	h = a.h;
	// printf("line2\n");
	// printf("m = %f \n", m);
	if (m <= 1.0 && m >= -1.0)
	{
		mh = (float)(b.h - a.h) / (float)(b.x - a.x);
		while (a.x >= b.x && a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
		{
			// printf("y = %f, a.y = %i a.x = %i \n", y, a.y, a.x);
			ft_find_color(a, e);
			y -= m;
			h -= mh;
			a.y = (int)(y + 0.5);
			a.h = (int)(h + 0.5);
			a.x--;
		}
	}
}

void ft_vertical(t_point a, t_point b, t_env *e)
{
	float h;
	float mh;
	
	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	while (a.y <= b.y && a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
	{
		ft_find_color(a, e);
		a.y++;
		h += mh;
		a.h = (int)(h + 0.5);
	}
}

void ft_vertical2(t_point a, t_point b, t_env *e)
{
	float h;
	float mh;
	
	mh = (float)(b.h - a.h) / (float)(b.y - a.y);
	h = a.h;
	while (a.y >= b.y && a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
	{
		ft_find_color(a, e);
		a.y--;
		h -= mh;
		a.h = (int)(h + 0.5);
	}
}

// void ft_horizontal(t_point a, t_point b, t_env *e)
// {
// 	float h;
// 	float mh;
	
// 	mh = (float)(b.h - a.h) / (float)(b.x - a.x);
// 	h = a.h;
// 	while (a.x <= b.x && a.x < e->winx && a.y < e->winy && a.x >= 0 && a.y >= 0)
// 	{
// 		ft_find_color(a, e);
// 		a.x++;
// 		h += mh;
// 		a.h = (int)(h + 0.5);
// 	}
// }

void ft_drawline(t_point *a, t_point *b, t_env *e)
{
	float m;
	t_point *point;

	if (a->x == b->x)
	{
		if (a->y > b->y)
		{
			point = a;
			a = b;
			b = point;
		}
		if (a->y > 0)
			ft_vertical(*a, *b, e);
		else
			ft_vertical2(*b, *a, e);
	}
	else
	{

		m = (float)(b->y - a->y) / (float)(b->x - a->x);
		if (m >= 0 && m <= 1)
		{
			if (a->x > 0 && a->y > 0)
				ft_line(*a, *b, e, m);
			else
				ft_line2(*b, *a, e, m);
		}
		else if (m < 0 && m >= -1)
		{
			if (a->x < e->winx && a->y < e->winx)
				ft_line2(*b, *a, e, m);
			else
				ft_line(*b, *a, e, m);
		}
		else
		{
			m = (float)(b->x - a->x) / (float)(b->y - a->y);
			printf("a.x = %i a.y = %i b.x = %i b.y = %i\n", a->x, a->y, b->x, b->y);
			printf("m = %f\n", m);
			if (m >= 0 && m <= 1)
			{
				if (a->x > 0 && a->y > 0)
					highline(*a, *b, e, m);
				else
					highline2(*b, *a, e, m);
			}
			else if (m < 0 && m >= -1)
			{
				if (a->x < e->winx && a->y < e->winx)
					highline2(*b, *a, e, m);
				else
					highline(*b, *a, e, m);
			}
		}
	}
}
	// printf("a.x = %i a.y = %i b.x = %i b.y = %i\n", a->x, a->y, b->x, b->y);
