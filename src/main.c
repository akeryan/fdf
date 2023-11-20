/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/20 16:27:38 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int main(int argc, char *argv[])
{
	t_idata	i_d;
	unsigned int color_value;
	int color = 0xAB48EF;

	
	//void *mlx = mlx_init();
    //void *win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Tutorial Window - Create Image");
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
	//int **arr = map_to_array(map);
	//int rows = get_num_of_rows(map);
	//int cols = get_num_of_columns(map);
	t_map *map = read_map(argv[1]);
	print_lst(map);

    //mlx_loop(mlx);
}