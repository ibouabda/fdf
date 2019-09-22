/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_too_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:30:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/23 00:16:29 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point interpret(int x, int y, int z, t_env *e)
{
	t_point point;

	point.x = e->posx + (x - z) / sqrt(2);
	point.y = e->posy + (x + 2 * y + z) / sqrt(6);
	point.h = z;

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
		a = interpret(tabx * e->zoom, taby * e->zoom,
		e->dbtab[taby][tabx] * e->alt, e);
		if (tabx + 1 < e->size)
		{
			b = interpret((tabx + 1) * e->zoom, taby * e->zoom,
			e->dbtab[taby][tabx + 1] * e->alt, e);
			ft_drawline(&a, &b, e);
		}
		if (e->dbtab[taby + 1])
		{
			b = interpret(tabx * e->zoom, (taby + 1) * e->zoom,
			e->dbtab[taby + 1][tabx] * e->alt, e);
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