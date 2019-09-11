/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:46:58 by retounsi          #+#    #+#             */
/*   Updated: 2019/03/11 10:23:20 by retounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *m;
	t_list *newm;

	if (!lst)
		return (0);
	m = lst;
	newlst = ft_lstnew(f(m)->content, f(m)->content_size);
	m = m->next;
	newm = newlst;
	while (m)
	{
		newm->next = ft_lstnew(f(m)->content, f(m)->content_size);
		newm = newm->next;
		m = m->next;
	}
	return (newlst);
}
