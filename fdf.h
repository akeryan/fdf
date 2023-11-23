/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:35 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/23 17:07:59 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
//# include <math.h>
# include <fcntl.h>
# include "mlx.h" 
# include "libft.h"

# define WINDOW_WIDTH 800 
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1
# define COLOR 0xFF0000

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	void	*img;
	char	*buf;
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

typedef struct s_quad
{
	int	dx;
	int	dy;
	int	i;
	int	d;
}	t_quad;

typedef struct s_pnt3d
{
	float	x;
	float	y;
	float	z;
	float	w;
	int		iso_x;
	int		iso_y;
	t_pnt3d	*n;
	t_pnt3d	*w;	
}	t_pnt3d;

typedef struct s_obj3d
{
	t_pnt3d		**pts;
	int			rows;
	int			cols;
}	t_obj3d;

typedef struct s_iso3d
{
	t_pnt2d	**pts;
	int		rows;
	int		cols;
}	t_iso3d;

void		check_ptr(void *ptr);
void		mlx_end(void *mlx_ptr, void *win_ptr);
void		check_allocation(void *ptr);

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
void		plot(int x, int y, t_data *d);
void		plot_line(t_pair *p, t_data *d);
void		plot_line_low(t_pair *p, t_data *d);
void		plot_line_high(t_pair *p, t_data *d);

//3dobj
t_obj3d		*new_obj3d(int rows, int cols);
t_obj3d		*obj_from_map(t_lst *map);

//structs
void		*new_point(int x, int y);
void		*new_pair(int x0, int y0, int x1, int y1);
void		print_obj(t_obj3d *a);

#endif