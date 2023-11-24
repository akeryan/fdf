/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/24 19:58:03 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char *argv[])
{
	t_data	d;
 
	d.mlx = mlx_init();
    d.win = mlx_new_window(d.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Create Image");
	d.img = mlx_new_image(d.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	d.buf = mlx_get_data_addr(d.img, &d.pixel_bits, &d.line_bytes, &d.endian);
	d.step = 10;		
	t_lst *map = read_map(argv[1]);
	t_obj3d *obj = obj_from_map(map);
	magnify(obj, 30);
	draw_obj(obj, &d);
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
    mlx_key_hook(d.win, key_handler, &d);
	mlx_hook(d.win, 17, 0, close_window, NULL);
    mlx_loop(d.mlx);
	return (0);
}