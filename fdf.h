/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:35 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/22 12:50:21 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h" 
# include "libft.h"

# define WINDOW_WIDTH 800 
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

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

void		draw_pixel(char *buf, const int pix, const int color, const int endian);
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

#endif