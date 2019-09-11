/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:39:33 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 09:59:57 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t			length;
	unsigned int	tmp;
	char			*str;

	tmp = ((n < 0) ? -n : n);
	length = ((n < 0) ? 2 : 1);
	while (tmp)
	{
		tmp = tmp / 10;
		length++;
	}
	if (!(str = ft_strnew(length)))
		return (NULL);
	length--;
	str[0] = ((n < 0) ? '-' : '0');
	tmp = ((n < 0) ? -n : n);
	while (tmp && length--)
	{
		str[length] = '0' + tmp % 10;
		tmp = tmp / 10;
	}
	return (str);
}
