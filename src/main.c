/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/22 14:52:25 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char *argv[])
{
	t_data	sys;
	t_idata	i_d;
	void	*image;
	void	*buffer;
	unsigned int color;

	color = 0xFF0000;
	sys.mlx = mlx_init();
    sys.win = mlx_new_window(sys.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Tutorial Window - Create Image");
	image = mlx_new_image(sys.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	buffer = mlx_get_data_addr(image, &i_d.pixel_bits, &i_d.line_bytes, &i_d.endian);
	if (i_d.pixel_bits != 32)
		color = mlx_get_color_value(sys.mlx, color);
	int pix = 10*i_d.line_bytes + 10*4;
	draw_pixel(buffer, pix, color, i_d.endian);
	draw_pixel(buffer, pix, color, i_d.endian);
	draw_pixel(buffer, pix, color, i_d.endian);
	draw_pixel(buffer, pix, color, i_d.endian);
	mlx_put_image_to_window(sys.mlx, sys.win, image, 0, 0);
    mlx_key_hook(sys.win, key_handler, &sys);
	mlx_hook(sys.win, 17, 0, close_window, NULL);
    mlx_loop(sys.mlx);
}