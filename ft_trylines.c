/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trylines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:22:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/18 11:23:41 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_equ function(t_point a, t_point b)
{
	t_equ axb;

	axb.a = (b.x - a.x) / (b.y - a.y);
	printf("ax = %f\n", axb.a);
	axb.b = (b.x * axb.a);
	printf("+ b = %f\n", axb.b);
	return (axb);
}

void ft_trylines(t_point a, t_point b, t_env *e)
{
	float dx;
	float dy;
	float ax;
	float eps; 
	t_point point;

	dx = ABS(b.x - a.x);
	dy = ABS(b.x - a.x);
	ax = dy/dx;
	eps = 0;
	point = a;
	// printf(" a.x = %i, a.y = %i\n", a.x, a.y);
	// printf(" b.x = %i, b.y = %i\n", b.x, b.y);
	while (point.x <= b.x)
	{
		// printf(" x = %i, y = %i\n", point.x, point.y);
		ft_fill_pixel(point, 255, e);
		eps-=ax;
		if (eps < -0.5)
		{
			point.y--;
			eps+=1.0;
		}
		point.x++;
	}
}