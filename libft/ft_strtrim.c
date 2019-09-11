/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 09:30:46 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:04:37 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_trim(const char *s)
{
	size_t	end;
	size_t	start;
	size_t	i;

	start = 0;
	end = 0;
	i = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n'
		|| s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		end++;
		i--;
	}
	return ((ft_strlen(s) - (start + end)));
}

char		*ft_strtrim(const char *s)
{
	int		i;
	char	*str;
	int		size;

	if (!s)
		return (NULL);
	size = ft_strlen_trim(s);
	i = 0;
	if (!(str = malloc(sizeof(char) * ft_strlen_trim(s) + 1)))
		return (0);
	str[size] = '\0';
	size--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (size >= 0)
	{
		str[size] = s[i + size];
		size--;
	}
	return (str);
}
