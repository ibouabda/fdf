/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:28:54 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/12 10:10:40 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelstr(t_list *alst)
{
	if (alst)
	{
		if (alst->next)
			ft_lstdelstr(alst->next);
		if (alst->content)
			ft_memdel((void**)&(alst->content));
		if (alst)
		ft_memdel((void**)&alst);
	}
}
