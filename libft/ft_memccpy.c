/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:26:12 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:00:54 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*mydest;
	char	*mysrc;
	char	myc;

	i = 0;
	myc = (unsigned char)c;
	mydest = (char*)dest;
	mysrc = (char*)src;
	while (i < n)
	{
		mydest[i] = mysrc[i];
		if (mydest[i] == myc)
			return (mydest + i + 1);
		i++;
	}
	return (NULL);
}
