/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:01:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 22:27:01 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	origin_x(t_obj3d * obj);
static void	origin_y(t_obj3d * obj);
static void	origin_z(t_obj3d * obj);

void	put_obj_to_origin(t_obj3d *obj)
{
	origin_x(obj);
	origin_y(obj);
	origin_z(obj);
	print_obj(obj);
}

static void	origin_x(t_obj3d *obj)
{
	float	min;
	float	max;
	float	av;
	int		i;

	i = 0;
	min = obj->a[0].x;
	max = obj->a[0].x;
	while (++i < obj->len)
	{
		if (min > obj->a[i].x)
			min = obj->a[i].x;
		if (max < obj->a[i].x)
			max = obj->a[i].x;
	}
	av = (min + max) / 2;
	i = -1;
	while (++i < obj->len)
		obj->a[i]._x -= av;
}

static void	origin_y(t_obj3d *obj)
{
	float	min;
	float	max;
	float	av;
	int		i;

	i = 0;
	min = obj->a[0].y;
	max = obj->a[0].y;
	while (++i < obj->len)
	{
		if (min > obj->a[i].y)
			min = obj->a[i].y;
		if (max < obj->a[i].y)
			max = obj->a[i].y;
	}
	av = (min + max) / 2;
	i = -1;
	while (++i < obj->len)
		obj->a[i]._y -= av;
}

static void	origin_z(t_obj3d *obj)
{
	float	min;
	float	max;
	float	av;
	int		i;

	i = 0;
	min = obj->a[0].z;
	max = obj->a[0].z;
	while (++i < obj->len)
	{
		if (min > obj->a[i].z)
			min = obj->a[i].z;
		if (max < obj->a[i].z)
			max = obj->a[i].z;
	}
	av = (min + max) / 2;
	i = -1;
	while (++i < obj->len)
		obj->a[i]._z -= av;
}

void	print_obj(t_obj3d *obj)
{
	int	i;

	i = -1;
	while (++i < obj->len)
		printf("%d - x: %.1f, y: %.1f, z: %.1f\n", i, obj->a[i]._x, obj->a[i]._y, obj->a[i]._z);
}