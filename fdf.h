/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:08:41 by retounsi          #+#    #+#             */
/*   Updated: 2019/10/01 18:30:23 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define ESC 53

# define A 0
# define B 11
# define C 8
# define D 2
# define E 14
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

# define TWO 19
# define THREE 20

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

# define FDF "FDF"
# define BEGIN "Let's Play : Press On ENTER"
# define PROJ "Change Projection : P"
# define MOVE "Move : Arrows"
# define ANGLE "Change Angle : WASD"
# define ZOOM "Zoom/Unzoom : 2/3"
# define INC "Increase/Decrease : Q/E"
# define PAUSE "Pause : ESC"
# define RESET "Reset : R"
# define QUIT "If You Wanna Quit The Game Press On ESC"
# define ENTER 36

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_env
{
	int		bool;
	int		proj;
	int		zoom;
	int		zoomalt;
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
	void	*esc_img_ptr;
	void	*img_ptr;
	char	*img_string;
}				t_env;

int				read_file(int fd, int ***dbtab);
void			ft_exit(int err, int **dbtable, t_list *m);
void			table_too_img(t_env *e);
void			ft_fill_pixel(t_point point, int color, t_env *e);
int				ft_drawline(t_point *a, t_point *b, t_env *e);
void			ft_find_color(t_point a, t_env *e);
void			new_window(t_env *e);
void			new_img(t_env *e);
void			img(t_env *e);
t_point			interpret(int x, int y, int z, t_env *e);
void			interface(t_env *e);
int				ft_key_hook(int keycode, t_env *e);
void			begin(t_env *e);
void			ft_maxmin(t_env *e);
void			ft_vertical2(t_point a, t_point b, t_env *e);
void			ft_vertical(t_point a, t_point b, t_env *e);
void			ft_line2(t_point a, t_point b, t_env *e, float m);

#endif
