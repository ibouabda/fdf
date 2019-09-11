/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:12:52 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 11:08:01 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_m;

	if (!(new_m = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new_m->content = NULL;
		new_m->content_size = 0;
	}
	else
	{
		if (!(new_m->content = malloc(sizeof(content_size))))
			return (NULL);
		new_m->content_size = content_size;
		ft_memcpy(new_m->content, content, content_size);
	}
	new_m->next = NULL;
	return (new_m);
}
