/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:31:35 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/16 14:00:25 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include "./minilibx/mlx.h" 

# define WINDOW_WIDTH 800 
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1


typedef struct s_img_data 
{
	int pixel_bits;
	int line_bytes; 
	int endian;
}	t_img_data;


void colorize_pixel(void *mlx, char *buffer, int pixel, int color, t_img_data i_d);
void check_ptr(void *ptr);
void mlx_end(void *mlx_ptr, void *win_ptr);

# endif 