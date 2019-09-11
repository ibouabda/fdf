/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dstrin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:38:54 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 09:59:14 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_2dstrin(char **s1, char ***s2)
{
	size_t i;

	i = 0;
	while (s2[i])
	{
		if (ft_2dstrcmp(s1, s2[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int			ft_3dstrin(char ***s1, char ***s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		if (ft_2dstrin(s1[i], s2) == 0)
			return (0);
		i++;
	}
	return (1);
}
