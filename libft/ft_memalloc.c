/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:42:02 by ibouabda          #+#    #+#             */
/*   Updated: 2019/08/29 13:30:34 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * size)))
	{
		ft_putendl("ft_memalloc malloc error");
		exit(EXIT_FAILURE);
	}
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
