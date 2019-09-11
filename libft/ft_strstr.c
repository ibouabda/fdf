/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:40:26 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:04:19 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int to_find_size;

	i = 0;
	to_find_size = ft_strlen(to_find);
	if (to_find_size <= 0)
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (j == to_find_size)
				return ((char*)str + i);
		}
		i++;
	}
	return (0);
}
