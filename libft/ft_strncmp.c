/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 18:28:52 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:03:53 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (0);
	n--;
	while (s1[i] != '\0' && s1[i] == s2[i] && n-- > 0)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
