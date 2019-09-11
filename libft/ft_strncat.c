/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:11:09 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:03:49 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int k;

	k = 0;
	i = ft_strlen(dest);
	while (src[k] && n > 0)
	{
		dest[i] = src[k];
		k++;
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
