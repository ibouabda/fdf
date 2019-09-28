/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dmemdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:29:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/28 14:45:39 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2dmemdel(void **as)
{
	size_t i;

	i = 0;
	if (as != NULL)
	{
		while (as[i])
		{
			free(as[i]);
			i++;
		}
		free(as);
		as = NULL;
	}
}
