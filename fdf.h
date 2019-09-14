/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retounsi <retounsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:08:41 by retounsi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/09/11 10:02:28 by retounsi         ###   ########.fr       */
=======
/*   Updated: 2019/09/12 17:24:57 by ibouabda         ###   ########.fr       */
>>>>>>> 0e7b28f7a2cc17b38b401ff0fe4ad16d4fea6445
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h> //a enlever
# include <fcntl.h>

int				read_file(int fd, int ***dbtab);
void			ft_exit(int **dbtable, t_list *m);

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_string;
}				t_env;

#endif
