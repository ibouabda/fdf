/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:31:49 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:03:26 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_split(const char *str, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		i++;
	}
	return (count);
}
