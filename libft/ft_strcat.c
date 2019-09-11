/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:27:10 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:02:33 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int k;

	k = 0;
	i = ft_strlen(dest);
	while (src[k])
	{
		dest[i] = src[k];
		k++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
