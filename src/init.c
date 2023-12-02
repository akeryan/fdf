/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:37:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/02 11:31:20 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init(t_data *d, char *str)
{
	t_lst	*map;

	d->width = WINDOW_WIDTH;
	d->height = WINDOW_HEIGHT;
	d->_angle = 5.0;
	d->_rad = d->_angle * M_PI / 180.0;
	map = read_map(str);
	d->obj = obj_from_map(map);
	free_list(map);
	d->obj->zoom = min(d->width, d->height) / max(d->obj->w, d->obj->h) / 2;
	d->_zoom = 20 / max(d->obj->w, d->obj->h);
	d->_pan = max(d->obj->h, d->obj->w) / min(d->width, d->height) * 400;
	d->obj->dx = d->width / 2;
	d->obj->dy = d->height / 2;
	d->obj->rx = asin(1 / sqrt(3));
	d->obj->ry = 0.0;
	d->obj->rz = 45 * M_PI / 180;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->width, d->height, "FDF");
	d->img = NULL;
	d->bonus_function_ptr = NULL;
	if (BONUS)
		d->bonus_function_ptr = &bonus_key_handler;
}