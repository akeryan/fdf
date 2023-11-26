/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:58:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 14:04:17 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static float	transform_x(t_obj3d *obj, t_data *d, int i);
static float	transform_y(t_obj3d *obj, t_data *d, int i);
static float	transform_z(t_obj3d *obj, t_data *d, int i);

void	transform(t_obj3d *obj, t_data *d)
{
	int	i;

	i = 0;
	while (i < obj->len)
	{
		obj->a[i].x = transform_x(obj, d, i);
		obj->a[i].y = transform_y(obj, d, i);
		obj->a[i].z = transform_z(obj, d, i);
		i++;
	}
}

static float	transform_x(t_obj3d *obj, t_data *d, int i)
{
	t_trans_vars	t;
	float			s;
	float			c;

	s = sin(d->_rad);
	c = cos(d->_rad);
	i = 0;
	t.w = obj->a[i]._x * obj->zoom * c * c;
	t.v = obj->a[i]._y * obj->zoom * (c * s * s - s * c);
	t.u = obj->a[i]._z * obj->zoom * (s * c * c + s * s);
	return (t.w + t.v + t.u + obj->zoom * obj->dx);
}

static float	transform_y(t_obj3d *obj, t_data *d, int i)
{
	t_trans_vars	t;
	float			s;
	float			c;

	s = sin(d->_rad);
	c = cos(d->_rad);
	i = 0;
	t.w = obj->a[i]._x * obj->zoom * s * c;
	t.v = obj->a[i]._y * obj->zoom * (s * s * s + c * c);
	t.u = obj->a[i]._z * obj->zoom * (s * s * c - s * c);
	return (t.w + t.v + t.u + obj->zoom * obj->dy);
}

static float	transform_z(t_obj3d *obj, t_data *d, int i)
{
	t_trans_vars	t;
	float			s;
	float			c;

	s = sin(d->_rad);
	c = cos(d->_rad);
	i = 0;
	t.w = -obj->a[i]._x * obj->zoom * s;
	t.v = obj->a[i]._y * obj->zoom * (s * c);
	t.u = obj->a[i]._z * obj->zoom * (c * c);
	return (t.w + t.v + t.u);
}