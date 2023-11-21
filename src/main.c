/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/21 20:14:50 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char *argv[])
{
	t_data	sys;
	t_idata	i_d;
	unsigned int color_value;
	int color = 0xAB48EF;

	sys.mlx = mlx_init();
    sys.win = mlx_new_window(sys.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Tutorial Window - Create Image");
	//void *image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	//char *buffer = mlx_get_data_addr(image, &i_d.pixel_bits, &i_d.line_bytes, &i_d.endian);
	//if (i_d.pixel_bits != 32)
		//color = mlx_get_color_value(mlx, color);

	//for(int y = 0; y < WINDOW_HEIGHT; ++y)
	//{
		//for(int x = 0; x < WINDOW_WIDTH; ++x)
		//{
			//int pixel = (y * i_d.line_bytes) + (x * 4);
			//if (i_d.pixel_bits != 32)
				//color = mlx_get_color_value(mlx, color);
			//colorize_pixel(buffer, pixel, color, i_d);
		//}
	//}
	//mlx_put_image_to_window(mlx, win, image, 0, 0);
	//t_lst	*map;
	//map = read_map(argv[1]);

	//print_map(map);
	//printf("%d\n", get_num_of_columns(map));
	//printf("num of nodes: %d\n", map->len);

	//t_array *a = array_from_map(map); 
	//print_arr(a);
	//mlx_loop_hook(sys.mlx, close_window, &sys);
    mlx_key_hook(sys.win, close_window, &sys);
    mlx_loop(sys.mlx);
	//mlx_destroy_window(sys->mlx, sys->win);
}