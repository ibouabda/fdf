/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:06:11 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/11 16:34:00 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int fd;

	(void)argc;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_putendl("error");
	if (read_file(fd) == 0)
		ft_putendl("error");
	close(fd);
	return (0);
}
