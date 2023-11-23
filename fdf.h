/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:35 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/23 10:20:32 by akeryan          ###   ########.fr       */
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
}	t_data;

typedef struct s_img_data
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
}	t_idata;

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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

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
}	t_pnt3d;

typedef struct s_obj3d
{
	t_pnt3d		**pts;
	int			rows;
	int			cols;
}	t_obj3d;

void		plot(int x, int y, char *buf, t_idata d);
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
void		plot_line(t_pair *p, char *buf, t_idata id);
void		plot_line_low(t_pair *p, char *buf, t_idata d);
void		plot_line_high(t_pair *p, char *buf, t_idata id);

//3dobj
t_obj3d		*new_obj3d(int rows, int cols);

//structs
void		*new_point(int x, int y);
void		*new_pair(int x0, int y0, int x1, int y1);

#endif