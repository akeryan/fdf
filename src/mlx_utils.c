/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 10:58:30 by akeryan          ###   ########.fr       */
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
	d->_pan = 10.0;
	d->_zoom = 0.1;
	map = read_map(str);
	d->obj = obj_from_map(map);
	d->obj->dx = 0.0;
	d->obj->dy = 0.0;
	d->obj->zoom = 1.0;
	d->obj->rx = 0.0;
	d->obj->ry = 0.0;
	d->obj->rz = 0.0;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->width, d->height, "FDF");
	d->img = mlx_new_image(d->mlx, d->width, d->height);
	d->buf = mlx_get_data_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endian);
}

//void	cpy_to_iso(t_obj3d *obj)
//{
	//int	i;

	//i = 0;
	//while (i < obj->len)
	//{
		//obj->a[i].iso_x = obj->a[i].x + obj->dx;
		//obj->a[i].y = obj->a[i].y + obj->dy;
		//i++;
	//}
//}

void	render(t_data *d)
{
	//cpy_to_iso(d->obj);
	mlx_destroy_image(d->mlx, d->img);
	d->img = mlx_new_image(d->mlx, d->width, d->height);
	d->buf = mlx_get_data_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endian);
	draw_obj(d->obj, d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

