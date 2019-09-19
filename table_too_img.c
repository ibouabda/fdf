/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_too_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:30:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/19 18:22:19 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void interpret(t_point *point, t_3dpoint *pt3d, t_env *e)
{
	point->x = e->winx / 2 + (pt3d->x - pt3d->z) / sqrt(2);
	point->y = e->winy / 2 + (pt3d->x + 2 * pt3d->y + pt3d->z) / sqrt(6);
	point->h = pt3d->z;
}

void	table_too_img(t_env *e, int **dbtab,int size)
{
	int tabx;
	int taby;
	t_point a;
	t_point b;
	t_3dpoint	z;

	taby = 0;
	while (dbtab[taby])
	{
		tabx = 0;
		while (tabx < size)
		{
			t_3dpointval(&z, tabx * 10, taby * 10, dbtab[taby][tabx]);
			interpret(&a, &z, e);
			ft_fill_pixel(a, 255, e);
			if (tabx + 1 < size)
			{
				t_3dpointval(&z, (tabx + 1) * 10, taby * 10, dbtab[taby][tabx + 1]);
				interpret(&b, &z, e);
				ft_fill_pixel(b, 255, e);
			}
			if (dbtab[taby + 1])
			{
				t_3dpointval(&z, tabx * 10, (taby + 1) * 10, dbtab[taby + 1][tabx]);
				interpret(&b, &z, e);
				ft_fill_pixel(b, 255, e);
			}
			tabx++;
		}
		taby++;
	}
}

void interpret2(t_point *point, t_3dpoint *pt3d, t_env *e)
{
	point->x = e->winx / 3 + (pt3d->x - pt3d->z) / sqrt(2);
	point->y = e->winy / 3 + (pt3d->x + 2 * pt3d->y + pt3d->z) / sqrt(6);
	point->h = pt3d->z;
}

int	drawvertical(t_point a, t_point b, t_env *e)
{
	if (a.y > b.y)
		return (0);
	while(a.y <= b.y)
	{
		ft_fill_pixel(a, 255, e);
		a.y++;
	}
	return (1);
}

void	table_too_img2(t_env *e, int **dbtab,int size)
{
	int tabx;
	int taby;
	t_point a;
	t_point b;
	t_3dpoint	z;

	taby = 0;
	while (dbtab[taby])
	{
		tabx = 0;
		while (tabx < size)
		{
			t_3dpointval(&z, tabx * 30, taby * 30, dbtab[taby][tabx]);
			interpret2(&a, &z, e);
			if (tabx + 1 < size)
			{
				t_3dpointval(&z, (tabx + 1) * 30, taby * 30, dbtab[taby][tabx + 1]);
				interpret2(&b, &z, e);
				ft_drawline(&a, &b, e);
			}
			if (dbtab[taby + 1])
			{
				t_3dpointval(&z, tabx * 30, (taby + 1) * 30, dbtab[taby + 1][tabx]);
				interpret2(&b, &z, e);
				ft_drawline(&a, &b, e);
			}
			tabx++;
		}
		taby++;
	}
}