/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:16:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:01:37 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_inverted_memcpy(void *dest, const void *src, size_t n)
{
	int i;

	i = n - 1;
	while (i >= 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i--;
	}
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if (dest > src)
		ft_inverted_memcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
