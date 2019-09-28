/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dputtabint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:55:44 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/28 14:45:26 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2dputtabint(int **tab, int sizeline)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_puttabint(tab[i], sizeline);
		i++;
	}
}
