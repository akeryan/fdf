/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/24 15:36:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char *argv[])
{
	//t_data	d;
	//t_pair	*p;
 
	//printf("HRERER1111");
	//d.mlx = mlx_init();
    //d.win = mlx_new_window(d.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Create Image");
	//d.img = mlx_new_image(d.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	//d.buf = mlx_get_data_addr(d.img, &d.pixel_bits, &d.line_bytes, &d.endian);
////	int pix = 10*d.line_bytes + 10*4;
	//printf("HRERER1111");
	t_lst *map = read_map(argv[1]);
	t_obj3d *obj = obj_from_map(map);
	print_obj(obj);
////	p = new_pair(100, 300, 20, 250);
	////t_p3d a, b;
	////a.i_x = 200;
	////a.i_y = 300;
	////b.i_x = 0;
	////b.i_y = 50;
	////plot_line(&a, &b, &d);
	//mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
    //mlx_key_hook(d.win, key_handler, &d);
	//mlx_hook(d.win, 17, 0, close_window, NULL);
    //mlx_loop(d.mlx);
	return (0);
}