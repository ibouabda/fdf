/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idris <idris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:08:41 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/20 16:11:58 by idris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h> //a enlever
# include <fcntl.h>
# include <math.h>


typedef struct	s_env
{
	int		zoom;
	int		alt;
	int		winx;
	int		winy;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_string;
}				t_env;

typedef struct	s_equ
{
	double		a;
	double		b;
}				t_equ;

void			create_img(int winx, int winy, t_env *e);
int				read_file(int fd, int ***dbtab);
void			ft_exit(int **dbtable, t_list *m);
void			table_too_img(t_env *e, int **dbtab,int size);
void			ft_fill_pixel(t_point point, int color, t_env *e);
void			create_img(int winx, int winy, t_env *e);
void			ft_trylines(t_point *a, t_point *b, t_env *e);
int				drawline(t_point a, t_point b, t_env *e);
void			table_too_img2(t_env *e, int **dbtab,int size);
int				drawvertical(t_point a, t_point b, t_env *e);
void			ft_drawline(t_point *a, t_point *b, t_env *e);
void			ft_find_color(t_point a, t_env *e);

#endif
