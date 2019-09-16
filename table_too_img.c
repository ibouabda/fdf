/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_too_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:30:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/16 17:49:10 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_equ	generate_function(t_point a, t_point b)
{
	t_equ	axb;

	if ((b.x - a.x) == 0)
	{
		axb.a = 0;
		axb.b = 0;
	}
	else if ((b.y - a.y) == 0)
	{
		axb.a = 0;
		axb.b = 0;
	}
	else
	{
		axb.a = (b.y - a.y) / (b.x - a.x);
		axb.b = b.y - (b.x * axb.a);
	}
	return (axb);
}

void interpret(t_point *point, t_3dpoint *pt3d, t_env *e)
{
	// x' = (x-z)/ sqrt(2)

	// y' = (x + 2y + z) / sqrt(6)
	// if (z->z != 0)
	// {
		point->x = e->winx / 2 + (pt3d->x - pt3d->z) / sqrt(2);
		point->y = e->winy / 2 + (pt3d->x + 2 * pt3d->y + pt3d->z) / sqrt(6);
	// }
	// else
	// {
	// 	point->x = e->winx / 2 + z->x;
	// 	point->y = e->winy / 2 + z->y;
	// }
	point->h = pt3d->z;
}

void	ft_calculate(t_point a, t_point b, t_equ axb, t_env *e)
{
	int x;
	int y;
	t_point point;

	x = a.x + 1;
	y = a.y + 1;
	ft_fill_pixel(a, 255, e);
	// while (x < b.x && y < b.y)
	// {
	// 	if ((b.x - a.x) == 0)
	// 	{
	// 		point.y = y;
	// 		point.x = a.x;
	// 	}
	// 	if ((b.y - a.y) == 0)
	// 	{
	// 		point.y = a.y;
	// 		point.x = x;
	// 	}
	// 	else
	// 	{
	// 		point.x = x;
	// 		point.y = axb.a * x + axb.b;
	// 	}
	// 	// if (x == 0)
	// 	// 	point.h = a.h;
	// 	// else if (a.h == 0 && b.h == 0)
	// 	// 	point.h = 0;
	// 	// else if (b.x == 0)
	// 	// 	point.h = b.h;
	// 	// else
	// 	// point.h = a.h + ((b.h - a.h) / (b.x / x));
	// 	ft_fill_pixel(point, 255, e);
	// 	x++;
	// 	y++;
	// }
	ft_fill_pixel(b, 255, e);
}

void	table_too_img(t_env *e, int **dbtab,int size)
{
	int tabx;
	int taby;
	t_point a;
	t_point b;
	t_3dpoint	z;

	taby = 0;
	while (dbtab[taby + 1])
	{
		tabx = 0;
		while (tabx < size - 1)
		{
			t_3dpointval(&z, tabx * 10, taby * 10, dbtab[taby][tabx]);
			interpret(&a, &z, e);
			t_3dpointval(&z, (tabx + 1) * 10, taby * 10, dbtab[taby][tabx + 1]);
			interpret(&b, &z, e);
			ft_calculate(a, b, generate_function(a, b), e);
			t_3dpointval(&z, tabx * 10, (taby + 1) * 10, dbtab[taby + 1][tabx]);
			interpret(&b, &z, e);
			ft_calculate(a, b, generate_function(a, b), e);
			tabx++;
		}
		taby++;
	}
}
	// if (!(z = (t_3dpoint*)malloc(sizeof(t_3dpoint))))
	// {
	// 	ft_putendl("malloc error t_3dpoint");
	// 	exit(EXIT_FAILURE);
	// }