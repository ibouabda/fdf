/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:30:52 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/11 11:28:23 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelm(t_list **alst)
{
	t_list *m;
	t_list *erase;

	m = *alst;
	while (m != NULL)
	{
		erase = m;
		m = m->next;
		if (erase->content)
			free(erase->content);
		free(erase);
	}
	*alst = NULL;
}