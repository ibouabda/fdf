/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:24:37 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:04:11 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;
	size_t to_find_size;

	i = 0;
	to_find_size = ft_strlen(to_find);
	if (to_find_size <= 0)
		return ((char*)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < n)
		{
			j++;
			if (j == to_find_size)
				return ((char*)str + i);
		}
		i++;
	}
	return (0);
}
