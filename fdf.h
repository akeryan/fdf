/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:35 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/06 19:25:10 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx/mlx.h" 
# include "./libft/libft.h"

# define WINDOW_WIDTH 1600 
# define WINDOW_HEIGHT 1200 
# define MLX_ERROR 1

# define TOP	0xFF0000
# define ZERO	0x14c314
# define BOTTOM	0x0000FF
# define ESC		53

# ifndef BONUS_AVAILABLE
#  define BONUS 0
# else 
#  define BONUS 	1
#  define KP_7		89	
#  define KP_8		91	
#  define KP_4		86	
#  define KP_5		87	
#  define KP_1		83	
#  define KP_2		84	
#  define LEFT		0	
#  define RIGHT		2 
#  define UP		13	
#  define DOWN		1	
#  define ZOOM_IN	69	
#  define ZOOM_OUT	78	
#  define M_1		18	
#  define M_2		19	
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
	uint32_t		col;
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
	float		z_ave;
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
	float	z_ave;
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
	uint32_t	color;
	int			dx;
	int			dy;
	int			_x;
	int			_y;
	int			i;
	int			d;
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
	int				hex;
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
int			close_window(void);
int			key_handler(int key, t_data *d);

//line
void		plot_line(t_p3d *a, t_p3d *b, t_data *d);

//3dobj
t_obj3d		*new_obj3d(int len);
t_obj3d		*obj_from_map(t_lst *map);
void		draw_obj(t_obj3d *obj, t_data *d);

//transformation
void		transform(t_obj3d *obj);
void		put_obj_to_origin(t_obj3d *obj);

//utils
float		min(float a, float b);
float		max(float a, float b);
uint32_t	get_hex_from_rgb(unsigned char r, unsigned char g, unsigned char b);
void		get_rgb_from_hex(uint32_t hex, uint8_t *r, uint8_t *g, uint8_t *b);

//plot
void		plot(int x, int y, t_data *d, int color);
uint32_t	get_color(uint32_t a_hex, uint32_t b_hex, int steps, int step);

//bonus
void		bonus_key_handler(int key, t_data *d);

#endif
