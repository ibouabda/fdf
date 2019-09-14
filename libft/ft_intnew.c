/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:06:48 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/12 11:05:31 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intnew(int size)
{
	int	*tab;

	if (!(tab = (int*)malloc(sizeof(int) * (size))))
	{
		ft_putendl("ft_intnew malloc error");
		exit(EXIT_FAILURE);
	}
	return (tab);
}