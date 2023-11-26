/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:19:30 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 10:57:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_handler(int key, t_data *d)
{
	printf("%d\n", key);
	if (key == 53)
		close_window(key, d);
	else if (key == 89)
	{
		d->_angle = -fabsf(d->_angle);
		rotate(d->obj, d, 'x');
		render(d);
	}
	else if (key == 91)
	{
		d->_angle = fabsf(d->_angle);
		rotate(d->obj, d, 'x');
		render(d);
	}
	else if (key == 86)
	{
		d->_angle = -fabsf(d->_angle);
		rotate(d->obj, d, 'y');
		render(d);
	}
	else if (key == 87)
	{
		d->_angle = fabsf(d->_angle);
		rotate(d->obj, d, 'y');
		render(d);
	}
	else if (key == 83)
	{
		d->_angle = -fabsf(d->_angle);
		rotate(d->obj, d, 'z');
		render(d);
	}
	else if (key == 84)
	{
		d->_angle = fabsf(d->_angle);
		rotate(d->obj, d, 'z');
		render(d);
	}
	else if (key == 13)
	{
		d->obj->dy -= d->_pan;
		//printf("dy: %d\n", d->obj->dy);
		translate(d->obj);
		render(d);
	}
	else if (key == 1)
	{
		d->obj->dy += d->_pan;
		//printf("dy: %d\n", d->obj->dy);
		translate(d->obj);
		render(d);
	}
	else if (key == 0)
	{
		d->obj->dx -= d->_pan;
		//printf("dx: %d\n", d->obj->dx);
		translate(d->obj);
		render(d);
	}
	else if (key == 2)
	{
		d->obj->dx += d->_pan;
		//printf("dx: %d\n", d->obj->dx);
		translate(d->obj);
		render(d);
	}
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