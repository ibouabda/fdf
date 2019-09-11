/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:05:43 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:05:51 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_size(const char *str, int c, int i)
{
	size_t k;

	k = 0;
	while (str[i] != c)
	{
		i++;
		k++;
	}
	return (k);
}

static int	ft_count_word(const char *s, char c)
{
	int i;
	int count;
	int check;

	check = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			check = 1;
		if (((check == 1 && s[i] != c) || (i == 0 && s[i] != c)) && s[i])
		{
			count++;
			check = 0;
		}
		i++;
	}
	return (count);
}

static char	**ft_strspliter(const char *s, char c, int i, int word)
{
	char	**splited;
	int		count;
	int		b;

	b = 0;
	count = 0;
	if (!(splited = (char**)malloc(sizeof(char *) * ft_count_word(s, c) + 1)))
		return (0);
	splited[ft_count_word(s, c)] = 0;
	while (word-- > 0)
	{
		while (s[i] == c && s[i])
			i++;
		if (!(splited[count] = (char*)malloc(sizeof(char) *
		ft_word_size(s, c, i) + 1)))
			return (0);
		while (s[i] != c && s[i])
		{
			splited[count][b++] = s[i];
			i++;
		}
		splited[count++][b] = '\0';
		b = 0;
	}
	return (splited);
}

char		**ft_strsplit(const char *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_strspliter(s, c, 0, ft_count_word(s, c)));
}
