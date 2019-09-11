/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:12:55 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:00:07 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *mylst;
	t_list *dellst;

	mylst = *alst;
	while (mylst)
	{
		dellst = mylst;
		mylst = mylst->next;
		del(dellst->content, dellst->content_size);
		free(dellst);
	}
	*alst = NULL;
}
