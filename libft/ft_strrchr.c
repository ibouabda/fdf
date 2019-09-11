/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:21:47 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:04:15 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*mys;

	mys = (char *)s;
	i = ft_strlen(mys) - 1;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (i >= 0)
	{
		if (s[i] == c)
			return (mys + i);
		i--;
	}
	return (NULL);
}
