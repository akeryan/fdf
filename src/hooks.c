/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:19:30 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 14:49:01 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_handler(int key, t_data *d)
{
	printf("%d\n", key);
	if (key == 53)
		close_window(key, d);
	else if (key == 89)
		d->obj->rx -= d->_rad;
	else if (key == 91)
		d->obj->rx += d->_rad;
	else if (key == 86)
		d->obj->ry -= d->_rad;
	else if (key == 87)
		d->obj->ry += d->_rad;
	else if (key == 83)
		d->obj->rz -= d->_rad;
	else if (key == 84)
		d->obj->rz += d->_rad;
	else if (key == 13)
		d->obj->dy -= d->_pan;
	else if (key == 1)
		d->obj->dy += d->_pan;
	else if (key == 0)
		d->obj->dx -= d->_pan;
	else if (key == 2)
		d->obj->dx += d->_pan;
	else if (key == 78)
		d->obj->zoom -= d->_zoom;
	else if (key == 69)
		d->obj->zoom += d->_zoom;
	transform(d->obj, d);
	render(d);
	return (0);
}

int	close_window(int key, t_data *d)
{
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
}

int	get_keycode(int key, t_data *d)
{
	printf("%d\n", key);
	return (0);
}