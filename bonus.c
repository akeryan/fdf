/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:08:10 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/30 22:34:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bonus_key_handler(int key, t_data *d)
{
	if (key == KP_7)
		d->obj->rx -= d->_rad;
	else if (key == KP_8)
		d->obj->rx += d->_rad;
	else if (key == KP_4)
		d->obj->ry -= d->_rad;
	else if (key == KP_5)
		d->obj->ry += d->_rad;
	else if (key == KP_1)
		d->obj->rz -= d->_rad;
	else if (key == KP_2)
		d->obj->rz += d->_rad;
	else if (key == UP)
		d->obj->dy -= d->_pan;
	else if (key == DOWN)
		d->obj->dy += d->_pan;
	else if (key == LEFT)
		d->obj->dx -= d->_pan;
	else if (key == RIGHT)
		d->obj->dx += d->_pan;
	else if (key == ZOOM_OUT)
		d->obj->zoom -= d->_zoom;
	else if (key == ZOOM_IN)
		d->obj->zoom += d->_zoom;
	else if (key == M_2)
	{
		d->obj->rz = 45 * M_PI / 180;
		d->obj->rx = asin(1 / sqrt(3));
		d->obj->ry = 0.0;
	}
	else if (key == M_1)
	{
		d->obj->rz = 0.0;
		d->obj->rx = 0.0;
		d->obj->ry = 0.0;
	}
}
