/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:08:41 by retounsi          #+#    #+#             */
/*   Updated: 2019/09/25 13:29:30 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define ESC 53

// dont work :
// # define LEFT_CLICK 1
// # define RIGHT_CLICK 2
// # define SCROLL_UP 4
// # define SCROLL_DOWN 5

# define A 0
# define B 11
# define C 8
# define D 2
// # define E 4
# define F 3
# define G 9
# define H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 12
# define R 15
# define S 1
# define T 17
# define U 32
# define V 9
# define W 13
# define X 7
# define Y 16
# define Z 6

# define ONE_NUM_PAD 83
# define TWO_NUM_PAD 84
# define THREE_NUM_PAD 85
# define FOUR_NUM_PAD 86
# define FIVE_NUM_PAD 87
# define SIX_NUM_PAD 88
# define SEVEN_NUM_PAD 89
# define EIGHT_NUM_PAD 91
# define NINE_NUM_PAD 92

# define LESS 78
# define MORE 69

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

# define ENTER 36

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h> //a enlever
# include <fcntl.h>
# include <math.h>


typedef struct	s_env
{
	int		proj;
	int		zoom;
	int		alt;
	int		max;
	int		min;
	int		**dbtab;
	int		size;
	int		sizey;
	int		posx;
	int		posy;
	int		angx;
	int		angy;
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
void			ft_exit(int err, int **dbtable, t_list *m);
void			table_too_img(t_env *e);
void			ft_fill_pixel(t_point point, int color, t_env *e);
void			create_img(int winx, int winy, t_env *e);
void			ft_trylines(t_point *a, t_point *b, t_env *e);
int				drawline(t_point a, t_point b, t_env *e);
int				drawvertical(t_point a, t_point b, t_env *e);
int				ft_drawline(t_point *a, t_point *b, t_env *e);
void			ft_find_color(t_point a, t_env *e);
void			new_window(int winx, int winy, t_env *e);
void			new_img(t_env *e);
void			img(t_env *e);
t_point			interpret(int x, int y, int z, t_env *e);

#endif
