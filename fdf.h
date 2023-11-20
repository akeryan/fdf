/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:35 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/20 10:45:21 by akeryan          ###   ########.fr       */
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

typedef struct s_2darray_size
{
	int	rows;
	int	columns;
}	t_2dsize;

typedef struct s_str
{
	char			*str;
	struct s_str	*next;
}	t_str;

void		colorize_pixel(char *buf, int pix, int color, t_idata d);
void		check_ptr(void *ptr);
t_2dsize	*get_map_dimensions(int fd);
void		mlx_end(void *mlx_ptr, void *win_ptr);
int			get_num_of_columns(t_str *map);
int			get_num_of_rows(t_str *map);
int			**new_2d_array(int rows, int cols);
int			**map_to_array(t_str *map);
t_str		*push_bottom(t_str *top, char *str);
t_str		*push_end(t_str *top, char *str);
void		free_list(t_str *top);
t_str		*read_map(char *file);


#endif