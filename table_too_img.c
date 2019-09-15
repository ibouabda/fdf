/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_too_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:30:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/15 14:24:33 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_equ	generate_function(t_point a, t_point b)
{
	t_equ	axb;

	axb.a = (b.y - a.y) / (b.x - a.x);
	axb.b = b.y - (b.x * axb.a);
	return (axb);
}
//ax+b = y   b = y - ax
void interpret(t_point *point, t_3dpoint *z, t_env *e)
{
	if (z->z != 0)
	{
		point->x = e->winx / 2 + point->x / z->z;
		point->y = e->winy / 2 + point->y / z->z;
	}
	else
	{
		point->x = e->winx / 2 + point->x;
		point->y = e->winy / 2 + point->y;
	}
}

void	table_too_img(t_env *e, int **dbtab,int size)
{
	int tabx;
	int taby;
	t_point a;
	t_point b;
	t_3dpoint z;

	// if (!(z = (t_3dpoint*)malloc(sizeof(t_3dpoint))))
	// {
	// 	ft_putendl("malloc error t_3dpoint");
	// 	exit(EXIT_FAILURE);
	// }
	taby = 0;
	tabx = 0;
	while (dbtab[taby + 1])
	{
		while (tabx < size - 1)
		{
			t_3dpointval(&z, tabx, taby, dbtab[taby][tabx]);
			interpret(&a, &z, e);
			t_3dpointval(&z, tabx + 1, taby, dbtab[taby][tabx]);
			interpret(&b, &z, e);
			
		}
	}
}