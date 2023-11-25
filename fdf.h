/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:35 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/25 10:46:03 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h" 
# include "libft.h"

# define WINDOW_WIDTH 800 
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

typedef struct s_p3d
{
	float			x;
	float			y;
	float			z;
	float			v;
	int				iso_x;
	int				iso_y;
	struct s_p3d	*n_ptr;
	struct s_p3d	*w_ptr;	
	int				color;
}	t_p3d;

typedef struct s_obj3d
{
	t_p3d		*pts;
	int			len;
}	t_obj3d;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		pix_bits;
	int		l_bytes;
	int		endian;
	void	*img;
	char	*buf;
	t_obj3d	*obj;
	int		width;
	int		height;
	int		margin;
	int		deg;
	int		pan;
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

typedef struct s_pnt2d
{
	int	x;
	int	y;
}	t_pnt2d;

typedef struct s_pair
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_pair;

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

typedef struct s_line_vars
{
	int		dx;
	int		dy;
	int		_x;
	int		_y;
	int		i;
	int		d;
}	t_line_vars;

void		check_ptr(void *ptr);
void		mlx_end(void *mlx_ptr, void *win_ptr);
void		check_allocation(void *ptr);
void		initialize(t_data *d, char *str);

//t_lst
t_node		*new_node(void);
void		free_list(t_lst *map);
void		push_bottom(t_lst *map, char *str);
t_lst		*read_map(char *file);
int			get_num_of_columns(t_lst *map);
void		print_map(t_lst *map);

//t_array
t_lst		*new_map(void);
t_array		*new_tarray(int rows, int cols);
void		print_arr(t_array *arr);
t_array		*array_from_map(t_lst *map);

//hooks
int			close_window(int key, t_data *d);
int			get_keycode(int key, t_data *d);
int			key_handler(int key, t_data *d);

//line
void		plot_line(t_p3d *a, t_p3d *b, t_data *d);

//3dobj
t_obj3d		*new_obj3d(int len);
t_obj3d		*obj_from_map(t_lst *map);
void		draw_obj(t_obj3d *obj, t_data *d);

//structs
void		*new_point(int x, int y);
void		*new_pair(int x0, int y0, int x1, int y1);
void		print_obj(t_obj3d *a);
void		magnify(t_obj3d *obj, int a);

#endif