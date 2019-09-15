/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:08:41 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/15 14:13:45 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h> //a enlever
# include <fcntl.h>


typedef struct	s_env
{
	int		winx;
	int		winy;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_string;
}				t_env;

typedef struct	s_equ
{
	int		a;
	int		b;
}				t_equ;

void			create_img(int winx, int winy, t_env *e);
int				read_file(int fd, int ***dbtab);
void			ft_exit(int **dbtable, t_list *m);
void			table_too_img(t_env *e, int **dbtab,int size);

#endif
