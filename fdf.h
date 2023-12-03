/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:35 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/03 08:47:04 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include "./minilibx/mlx.h" 
# include "./libft/libft.h"

# define WINDOW_WIDTH 800 
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

# define TOP	0xFF0000
# define ZERO	0x14c314
# define BOTTOM	0x0000FF

# ifndef BONUS_AVAILABLE
#  define BONUS 0
# else 
#  define BONUS 	1
#  define KP_7		65429
#  define KP_8		65431
#  define KP_4		65430
#  define KP_5		65437
#  define KP_1		65436
#  define KP_2		65433
#  define LEFT		97
#  define RIGHT		100 
#  define UP		119
#  define DOWN		115
#  define ZOOM_IN	65451
#  define ZOOM_OUT	65453
#  define M_1		49
#  define M_2		50
# endif

typedef struct s_p3d
{
	float			_x;
	float			_y;
	float			_z;
	float			x;
	float			y;
	float			z;
	struct s_p3d	*n_ptr;
	struct s_p3d	*w_ptr;	
	int				color;
}	t_p3d;

typedef struct s_obj3d
{
	t_p3d		*a;
	int			len;
	float		dx;
	float		dy;
	float		zoom;
	float		rx;
	float		ry;
	float		rz;
	int			h;
	int			w;
	float		z_min;
	float		z_max;
	float		z_average;
}	t_obj3d;

typedef struct s_data
{
	t_obj3d	*obj;
	void	*mlx;
	void	*win;
	int		pix_bits;
	int		l_bytes;
	int		endi;
	void	*img;
	char	*buf;
	int		buf_size;
	int		width;
	int		height;
	float	_angle;
	float	_rad;
	float	_pan;
	float	_zoom;
	int		z_ave;
	void	(*bonus_function_ptr)(int key, struct s_data *d);

}	t_data;

typedef struct s_array
{
	int	**arr;
	int	rows;
	int	cols;
}	t_array;

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

typedef struct s_lst
{
	t_node	*top;
	int		len;
}	t_lst;

typedef struct s_obj_vars
{
	t_obj3d	*obj;
	t_p3d	*to;
	t_node	*tn;
	char	**spl;
	int		rows;
	int		cols;
	int		i;
	int		j;
}	t_obj_vars;	

typedef struct s_plot_vars
{
	int		dx;
	int		dy;
	int		_x;
	int		_y;
	int		i;
	int		d;
	int		color;
}	t_plot_vars;

typedef struct s_trans_vars
{
	float	w;
	float	u;
	float	v;
	float	h;
}	t_trans_vars;

typedef struct s_rgb_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int	hex;
}	t_rgb_color;

typedef struct s_gradient_vars
{
	t_rgb_color	a;
	t_rgb_color	b;	
	int			range;
}	t_gradient_vars;


void		check_allocation(void *ptr);
void		init(t_data *d, char *str);
void		render(t_data *d);

//t_lst
t_node		*new_node(void);
void		free_list(t_lst *map);
void		push_bottom(t_lst *map, char *str);
t_lst		*read_map(char *file);
int			get_num_of_columns(t_lst *map);

//t_array
t_lst		*new_map(void);

//hooks
int			close_window(int key, t_data *d);
int			key_handler(int key, t_data *d);

//line
void		plot_line(t_p3d *a, t_p3d *b, t_data *d);

//3dobj
t_obj3d		*new_obj3d(int len);
t_obj3d		*obj_from_map(t_lst *map);
void		draw_obj(t_obj3d *obj, t_data *d);

//transformation
void		transform(t_obj3d *obj, t_data *d);
void		put_obj_to_origin(t_obj3d *obj);

//utils
float		min(float a, float b);
float		max(float a, float b);
int			get_hex_from_rgb(unsigned char r, unsigned char g, unsigned char b);
void		get_rgb_from_hex(int hexValue, unsigned char *r, unsigned char *g, unsigned char *b);

//bonus
void		bonus_key_handler(int key, t_data *d);

#endif