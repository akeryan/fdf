/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/22 18:41:05 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char *argv[])
{
	t_data	sys;
	t_idata	i_d;
	t_pair	*p;
	void	*image;
	void	*buffer;

	sys.mlx = mlx_init();
    sys.win = mlx_new_window(sys.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Tutorial Window - Create Image");
	image = mlx_new_image(sys.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	buffer = mlx_get_data_addr(image, &i_d.pixel_bits, &i_d.line_bytes, &i_d.endian);
	int pix = 10*i_d.line_bytes + 10*4;
	p = new_pair(100, 300, 20, 250);
	plot_line(p, buffer, i_d);
	mlx_put_image_to_window(sys.mlx, sys.win, image, 0, 0);
    mlx_key_hook(sys.win, key_handler, &sys);
	mlx_hook(sys.win, 17, 0, close_window, NULL);
    mlx_loop(sys.mlx);
}