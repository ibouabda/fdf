/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trylines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:22:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/17 15:09:19 by ibouabda         ###   ########.fr       */
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
	int x;
	int y;
	t_point point;
	t_equ axb;

	x = a.x;
	point.y = a.y;
	axb.a = 1;
	axb.b = 0;
	//ft_fill_pixel(a, 255, e);
	printf(" a.x = %i, a.y = %i\n", a.x, a.y);
	printf(" b.x = %i, b.y = %i\n", b.x, b.y);
	point.x = x;
	point.y = axb.a * x + axb.b + 0.5;
	while (x < 1280 && point.y < 720)
	{
		printf(" x = %i, y = %i\n", point.x, point.y);
		ft_fill_pixel(point, 255, e);
		x++;
		point.x = x;
		point.y = axb.a * x + axb.b + 0.5;
	}
	//ft_fill_pixel(b, 255, e);
}