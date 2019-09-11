/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:39:55 by retounsi          #+#    #+#             */
/*   Updated: 2019/04/18 17:35:55 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	c = 0;
	i = 0;
	if (!(str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (s1[i])
	{
		str[c] = s1[i];
		i++;
		c++;
	}
	i = 0;
	while (s2[i])
	{
		str[c] = s2[i];
		i++;
		c++;
	}
	str[c] = '\0';
	return (str);
}
