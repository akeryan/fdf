/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/25 10:22:35 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char *argv[])
{
	t_data	d;
	initialize(&d, argv[1]);
	magnify(d.obj, 30);
	draw_obj(d.obj, &d);
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
    mlx_key_hook(d.win, key_handler, &d);
	mlx_hook(d.win, 17, 0, close_window, NULL);
    mlx_loop(d.mlx);
	return (0);
}