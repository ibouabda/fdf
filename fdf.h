/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:08:41 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/11 10:52:47 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h> //a enlever
# include <fcntl.h>
int		read_file(int fd);

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_string;
}				t_env;

#endif
