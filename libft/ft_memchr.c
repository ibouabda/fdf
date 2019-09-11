/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 09:47:59 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:05:25 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	to_find;
	unsigned char	*mys;

	mys = (unsigned char*)s;
	to_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (mys[i] == to_find)
			return (&mys[i]);
		i++;
	}
	return (NULL);
}
