/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:58:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 18:27:33 by akeryan          ###   ########.fr       */
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

	t.w = obj->a[i]._x * cos(obj->ry) * cos(obj->rz);
	t.h = cos(obj->rz) * sin(obj->rx) * sin(obj->ry);
	t.v = obj->a[i]._y * (t.h - sin(obj->rz) * cos(obj->rx));
	t.h = cos(obj->rx) * sin(obj->ry) * cos(obj->rz);
	t.u = obj->a[i]._z * (t.h + sin(obj->rx) * sin(obj->rz));
	return (obj->zoom * (t.w + t.v + t.u + obj->dx));
}

static float	transform_y(t_obj3d *obj, t_data *d, int i)
{
	t_trans_vars	t;

	t.w = obj->a[i]._x * cos(obj->ry) * sin(obj->rz);
	t.h = sin(obj->rx) * sin(obj->ry) * sin(obj->rz);
	t.v = obj->a[i]._y * (t.h + cos(obj->rx) * cos(obj->rz));
	t.h = cos(obj->rx) * sin(obj->ry) * sin(obj->rz);
	t.u = obj->a[i]._z * (t.h - sin(obj->rx) * cos(obj->rz));
	return (obj->zoom * (t.w + t.v + t.u + obj->dy));
}

static float	transform_z(t_obj3d *obj, t_data *d, int i)
{
	t_trans_vars	t;

	t.w = -obj->a[i]._x * sin(obj->ry);
	t.v = obj->a[i]._y * sin(obj->rx) * cos(obj->ry);
	t.u = obj->a[i]._z * cos(obj->rx) * cos(obj->ry);
	return (obj->zoom * (t.w + t.v + t.u));
}