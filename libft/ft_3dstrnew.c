/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dstrnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:51:45 by ibouabda          #+#    #+#             */
/*   Updated: 2019/03/11 09:59:18 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	***ft_3dstrnew(size_t size)
{
	char	***str;
	size_t	i;

	i = 0;
	if (!(str = (char***)malloc(sizeof(char**) * size + 1)))
	{
		return (NULL);
	}
	while (i < size + 1)
	{
		str[i] = NULL;
		i++;
	}
	return (str);
}
