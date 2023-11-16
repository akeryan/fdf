/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/16 14:00:15 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void check_ptr(void *ptr)
{
	if(ptr == NULL)
	{
		printf("ptr is NULL\n");
        exit(MLX_ERROR);
	}
}
void mlx_end(void *mlx_ptr, void *win_ptr)
{
    mlx_destroy_window(mlx_ptr, win_ptr);
    free(mlx_ptr);
}

void colorize_pixel(void *mlx, char *buffer, int pixel, int color, t_img_data i_d)
{
	if (i_d.pixel_bits != 32)
		color = mlx_get_color_value(mlx, color);

	if (i_d.endian == 1)        // Most significant (Alpha) byte first
	{
		buffer[pixel + 0] = (color >> 24);
		buffer[pixel + 1] = (color >> 16) & 0xFF;
		buffer[pixel + 2] = (color >> 8) & 0xFF;
		buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (i_d.endian == 0)   // Least significant (Blue) byte first
	{
		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
	}
}