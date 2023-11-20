/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:35 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/20 19:46:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "./minilibx/mlx.h" 
# include "../libft/libft.h"

# define WINDOW_WIDTH 800 
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

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
} t_array;

typedef struct s_2darray_size
{
	int	rows;
	int	columns;
}	t_2dsize;

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

typedef struct s_map
{
	t_node	*top;
	int		len;
}	t_map;

void		colorize_pixel(char *buf, int pix, int color, t_idata d);
void		check_ptr(void *ptr);
void		mlx_end(void *mlx_ptr, void *win_ptr);
int			get_num_of_columns(t_map *map);
t_array		*new_tarray(int rows, int cols);
//int			**map_to_array(t_lst *map);
void		push_bottom(t_map *top, char *str);
void		free_list(t_map*top);
t_map		*read_map(char *file);
void		cpy_map_to_arr(int **arr, t_map *map);
void		check_allocation(void *ptr);

//t_lst
t_map		*new_map(void);
void		print_map(t_map *lst);

//t_array
void		print_arr(t_array *a);
t_array		*array_from_map(t_map *map);


#endif