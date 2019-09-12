/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:06:48 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/12 10:09:28 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intnew(int size)
{
	int	*str;
	int	i;

	i = 0;
	if (!(str = (int*)malloc(sizeof(int) * (size + 1))))
	{
		ft_putendl("ft_intnew malloc error");
		exit(EXIT_FAILURE);
	}
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}