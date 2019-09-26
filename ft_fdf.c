/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:22:01 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/26 18:20:30 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(int err, int **dbtable, t_list *m)
{
	if (dbtable)
		ft_2dmemdel((void**)dbtable);
	if (m)
		ft_lstdelstr(m);
	if (err == 1)
		ft_putendl("error");
	exit(err);
}

void	interface(t_env *e)
{
	int a;

	a = e->winy / 23;

	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(FDF) * 5, e->winy / 2.5 - a, 0xD50097, FDF);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(BEGIN) * 5, e->winy / 2.5, 0x0000FF, BEGIN);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(MOVE) * 5, e->winy / 2.5 + a * 2, 0x0000FF, MOVE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ANGLE) * 5, e->winy / 2.5 + a * 3, 0xD50097, ANGLE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ZOOM) * 5, e->winy / 2.5 + a * 4, 0x0000FF, ZOOM);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(INC) * 5, e->winy / 2.5 + a * 5, 0xD50097, INC);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(INC) * 5, e->winy / 2.5 + a * 6, 0x0000FF, PROJ);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(PAUSE) * 5, e->winy / 2.5 + a * 7, 0xD50097, PAUSE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(RESET) * 5, e->winy / 2.5 + a * 8, 0x0000FF, RESET);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(QUIT) * 5, e->winy / 2.5 + a * 9, 0xD50097, QUIT);
}

void	pause2(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(FDF) * 5, e->winy / 2, 0xFFFFFF, FDF);
	// mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(BEGIN) * 5, e->winy / 2 + 40, 0xFFFFFF, BEGIN);
	// mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(INSTR) * 5, e->winy / 2 + 80, 0xFFFFFF, INSTR);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(MOVE) * 5, e->winy / 2 + 80, 0xFFFFFF, MOVE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ANGLE) * 5, e->winy / 2 + 120, 0xFFFFFF, ANGLE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(ZOOM) * 5, e->winy / 2 + 160, 0xFFFFFF, ZOOM);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(INC) * 5, e->winy / 2 + 200, 0xFFFFFF, INC);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(PAUSE) * 5, e->winy / 2 + 240, 0xFFFFFF, PAUSE);
	mlx_string_put(e->mlx_ptr, e->win_ptr, e->winx / 2 - ft_strlen(QUIT) * 5, e->winy / 2 + 280, 0xFFFFFF, QUIT);
}