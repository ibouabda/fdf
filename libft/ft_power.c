/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:30:47 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:01:46 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_power(long n, int power)
{
	int n2;

	n2 = n;
	while (power > 1)
	{
		n *= n2;
		power--;
	}
	return (n);
}
