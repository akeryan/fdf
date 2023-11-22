/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/22 14:49:34 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	check_ptr(void *ptr)
{
	if (ptr == NULL)
	{
		printf("ptr is NULL\n");
		exit(MLX_ERROR);
	}
}

void	mlx_end(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
}

void	check_allocation(void *ptr)
{
	if (ptr == NULL)
	{
		perror("Memory allocation failed");
		exit (EXIT_FAILURE);
	}
}

void	draw_pixel(char *buf, int pix, int color, int endian)
{
	if (endian == 1)
	{
		buf[pix + 0] = (color >> 24);
		buf[pix + 1] = (color >> 16) & 0xFF;
		buf[pix + 2] = (color >> 8) & 0xFF;
		buf[pix + 3] = (color) & 0xFF;
	}
	else if (endian == 0)
	{
		buf[pix + 0] = (color) & 0xFF;
		buf[pix + 1] = (color >> 8) & 0xFF;
		buf[pix + 2] = (color >> 16) & 0xFF;
		buf[pix + 3] = (color >> 24);
	}
}

//void	draw_line(char *buf, int x1, int y1, int x2, int y2, int color)
//{

//}


	
	//if (i_d.pixel_bits != 32)
		//color = mlx_get_color_value(sys.mlx, color);

	//for(int y = 0; y < WINDOW_HEIGHT; ++y)
	//{
		//for(int x = 0; x < WINDOW_WIDTH; ++x)
		//{
			//int pixel = (y * i_d.line_bytes) + (x * 4);
			//if (i_d.pixel_bits != 32)
				//color = mlx_get_color_value(sys.mlx, color);
			//draw_pixel(buffer, pixel, color, i_d.endian);
		//}
	//}
	//mlx_put_image_to_window(sys.mlx, sys.win, image, 0, 0);