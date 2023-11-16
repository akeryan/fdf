/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/16 13:59:20 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#include "mlx.h"

int main()
{
	t_img_data i_d;
	unsigned int color_value;
	int color = 0xAB48EF;

    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Tutorial Window - Create Image");
	void *image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	char *buffer = mlx_get_data_addr(image, &i_d.pixel_bits, &i_d.line_bytes, &i_d.endian);
	if (i_d.pixel_bits != 32)
		color = mlx_get_color_value(mlx, color);

	for(int y = 0; y < WINDOW_HEIGHT; ++y)
	{
		for(int x = 0; x < WINDOW_WIDTH; ++x)
		{
			int pixel = (y * i_d.line_bytes) + (x * 4);

			colorize_pixel(mlx, buffer, pixel, color, i_d);
		}
	}
	mlx_put_image_to_window(mlx, win, image, 0, 0);
	printf("pixel_bits: %d\n", i_d.pixel_bits);
	printf("line_bytes: %d\n", i_d.line_bytes);
	printf("endian: %d\n", i_d.endian);
	printf("color: %d\n", color);
    
    // The following code goes here.

    mlx_loop(mlx);
}