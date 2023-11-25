/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/25 22:15:28 by akeryan          ###   ########.fr       */
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

	d->width = 800;
	d->height = 600;
	d->margin = 30;
	d->angle = 5;
	d->pan = 10;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->width, d->height, "FDF");
	d->img = mlx_new_image(d->mlx, d->width, d->height);
	d->buf = mlx_get_data_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endian);
	map = read_map(str);
	d->obj = obj_from_map(map);
	d->obj->dx = 0;
	d->obj->dy = 0;
}

float	deg_to_rad(float degs)
{
	return ((degs * M_PI) / 180);
}

void	cpy_to_iso(t_obj3d *obj)
{
	int i;

	i = 0;
	while (i < obj->len)
	{
		obj->a[i].iso_x = obj->a[i].x;
		obj->a[i].iso_y = obj->a[i].y;
		i++;
	}
}

void	render(t_data *d)
{
	cpy_to_iso(d->obj);
	mlx_destroy_image(d->mlx, d->img);
	d->img = mlx_new_image(d->mlx, d->width, d->height);
	d->buf = mlx_get_data_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endian);
	draw_obj(d->obj, d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

