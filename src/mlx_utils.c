/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/27 13:13:10 by akeryan          ###   ########.fr       */
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
	d->_angle = 5.0;
	d->_rad = d->_angle * M_PI / 180.0;
	map = read_map(str);
	d->obj = obj_from_map(map);
	d->obj->zoom = min(d->width, d->height) / max(d->obj->w, d->obj->h) / 2;
	d->_zoom = 20 / max(d->obj->w, d->obj->h);
	d->_pan = max(d->obj->h, d->obj->w) / min(d->width, d->height) * 20;
	d->obj->dx = d->width / 2 / d->obj->zoom;
	d->obj->dy = d->height / 2 / d->obj->zoom;
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

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
