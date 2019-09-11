/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:24:23 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:03:04 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && (i != ft_strlen(s1)
				|| i != ft_strlen(s2)))
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
