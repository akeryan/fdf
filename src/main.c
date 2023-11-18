/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/18 13:14:46 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_idata	i_d;
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
			if (i_d.pixel_bits != 32)
				color = mlx_get_color_value(mlx, color);
			colorize_pixel(buffer, pixel, color, i_d);
		}
	}
	mlx_put_image_to_window(mlx, win, image, 0, 0);
	//printf("pixel_bits: %d\n", i_d.pixel_bits);
	//printf("line_bytes: %d\n", i_d.line_bytes);
	//printf("endian: %d\n", i_d.endian);
	//printf("color: %d\n", color);
    
	int fd = open(argv[1], O_RDONLY);
	if(!fd)
	{
		printf("fd is null\n");
		return (1);
	}

	t_2dsize *dims = get_map_dimensions(fd);
	printf("COLS: %d\n", dims->columns);
	printf("ROWS: %d\n", dims->rows);
	int **ar = map_to_array(fd);
	int j = 0;
	int i = 0;
	while(i < dims->rows)
	{
		j = 0;
		while (j < dims->columns)
		{
			printf("%d ", ar[i][j++]);
		}
		i++;
		printf("\n");
	}
	close(fd);
    mlx_loop(mlx);
}