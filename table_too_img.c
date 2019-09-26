/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_too_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:30:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/26 16:58:15 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point interpret(int x, int y, int z, t_env *e)
{
	t_point point;
	
	x = x * e->zoom;
	y = y * e->zoom;
	z = z * e->alt;
	point.h = z;
	if (e->proj == 0)
	{
		z = z * e->zoom / 20; // division par 20 a observer
		point.x = e->posx + (x - z) / sqrt(2);
		point.y = e->posy + (x + 2 * y + z) / sqrt(6);
	}
	if (e->proj == 1)
	{
		point.x = e->posx + (1000 * (x - e->angx)) / (1000 - z) + e->angx;
		point.y = e->posy + (1000 * (y - e->angy)) / (1000 - z) + e->angy;
	}
	return (point);
}

void	line_too_img(t_env *e, int taby)
{
	int tabx;
	t_point a;
	t_point b;

	tabx = 0;
	while (tabx < e->size)
	{
		a = interpret(tabx, taby, e->dbtab[taby][tabx], e);
		if (tabx + 1 < e->size)
		{
			b = interpret((tabx + 1), taby, e->dbtab[taby][tabx + 1], e);
			ft_drawline(&a, &b, e);
		}
		if (e->dbtab[taby + 1])
		{
			b = interpret(tabx, (taby + 1), e->dbtab[taby + 1][tabx], e);
			ft_drawline(&a, &b, e);
		}
		tabx++;
	}
}

void	table_too_img(t_env *e)
{
	int taby;

	taby = 0;
	while (e->dbtab[taby])
	{
		line_too_img(e, taby);
		taby++;
	}
}