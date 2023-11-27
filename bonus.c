/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:08:10 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/27 21:47:03 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bonus_key_handler(int key, t_data *d)
{
	if (key == 89)
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
}
