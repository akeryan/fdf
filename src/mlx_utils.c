/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 19:35:22 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	check_allocation(void *ptr)
{
	if (ptr == NULL)
	{
		perror("Memory allocation failed");
		exit (EXIT_FAILURE);
	}
}

void	initialize(t_data *d, char *str)
{
	t_lst	*map;

	d->width = 2400;
	d->height = 1200;
	d->_angle = 5.0;
	d->_rad = d->_angle * M_PI / 180.0;
	d->_pan = 1.0;
	d->_zoom = 1;
	map = read_map(str);
	d->obj = obj_from_map(map);
	d->obj->dx = 0.0;
	d->obj->dy = 0.0;
	d->obj->zoom = 30.0;
	d->obj->rx = asin(1 / sqrt(3));
	d->obj->ry = 0.0;
	d->obj->rz = 45 * M_PI / 180;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->width, d->height, "FDF");
}

void	render(t_data *d)
{
	if (d->img)
		mlx_destroy_image(d->mlx, d->img);
	d->img = mlx_new_image(d->mlx, d->width, d->height);
	d->buf = mlx_get_data_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endian);
	draw_obj(d->obj, d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}



