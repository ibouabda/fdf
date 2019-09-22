/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:22:01 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/22 20:39:05 by idris            ###   ########.fr       */
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