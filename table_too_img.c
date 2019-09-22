/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_too_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:30:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/22 12:21:42 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void interpret2(t_point *point, t_3dpoint *pt3d, t_env *e)
{
	point->x = e->winx / 9 + (pt3d->x - pt3d->z) / sqrt(2);
	point->y = e->winy / 9 + (pt3d->x + 2 * pt3d->y + pt3d->z) / sqrt(6);
	point->h = pt3d->z;
}

void	table_too_img(t_env *e)
{
	int tabx;
	int taby;
	t_point a;
	t_point b;
	t_3dpoint	z;

	taby = 0;
	while (e->dbtab[taby])
	{
		tabx = 0;
		while (tabx < e->size)
		{
			t_3dpointval(&z, tabx * e->zoom, taby * e->zoom, e->dbtab[taby][tabx] * e->alt);
			interpret2(&a, &z, e);
			if (tabx + 1 < e->size)
			{
				t_3dpointval(&z, (tabx + 1) * e->zoom, taby * e->zoom, e->dbtab[taby][tabx + 1] * e->alt);
				interpret2(&b, &z, e);
				ft_drawline(&a, &b, e);
			}
			if (e->dbtab[taby + 1])
			{
				t_3dpointval(&z, tabx * e->zoom, (taby + 1) * e->zoom, e->dbtab[taby + 1][tabx] * e->alt);
				interpret2(&b, &z, e);
				ft_drawline(&a, &b, e);
			}
			tabx++;
		}
		taby++;
	}
}