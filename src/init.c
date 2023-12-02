/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:37:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/02 22:37:14 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		set_z_min_max(t_obj3d *d);
static void		set_color(t_p3d *p, t_obj3d *obj, int a_hex, int b_hex);
static void		colorize(t_obj3d *obj);
static float	get_z_average(t_obj3d *obj);

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
	set_z_min_max(d->obj);
	colorize(d->obj);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->width, d->height, "FDF");
	d->img = NULL;
	d->bonus_function_ptr = NULL;
	if (BONUS)
		d->bonus_function_ptr = &bonus_key_handler;
}

static void	set_z_min_max(t_obj3d *obj)
{
	float	min;
	float	max;
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
	obj->z_max = max;
	obj->z_min = min;
}

static void	colorize(t_obj3d *obj)
{
	int		i;

	obj->z_average = get_z_average(obj);
	printf("ave: %.1f\n", obj->z_average);
	printf("z_max: %.1f\n", obj->z_max);
	printf("z_min: %.1f\n", obj->z_min);
	i = 0;
	while (i < obj->len)
	{
		if (obj->a[i]._z == 0)
			obj->a[i].color = ZERO;
		else
		{
			if (obj->a[i]._z >= obj->z_average)
				set_color(&obj->a[i], obj, ZERO, TOP);
			else
				set_color(&obj->a[i], obj, ZERO, BOTTOM);
		}
		i++;
	}
}

static void	set_color(t_p3d *p, t_obj3d *obj, int a_hex, int b_hex)
{
	t_gradient_vars	v;
	t_rgb_color		out;

	printf("==========================================\n");
	get_rgb_from_hex(a_hex, &v.a.r, &v.a.g, &v.a.b);
	printf("A: r-%d, g-%d, b-%d\n", v.a.r, v.a.g, v.a.b);
	get_rgb_from_hex(b_hex, &v.b.r, &v.b.g, &v.b.b);
	printf("B - r-%d, g-%d, b-%d\n", v.b.r, v.b.g, v.b.b);
	if (p->_z > obj->z_average)
	{
		v.range = obj->z_max - obj->z_average;
		printf("range: %d\n", v.range);
		printf("_z: %.1f\n", p->_z);
		int z_ave = p->_z - obj->z_average;
		printf("z - av:%d\n", z_ave);
		float br_ar = v.b.r - v.a.r;
		printf("b.r - a.r:%.1f\n", br_ar);
		int times = z_ave * br_ar;
		printf("times: %d\n", times);
		int div = times / v.range;
		printf("div: %d\n", div);
		out.r = v.a.r + (int)(p->_z - obj->z_average) * (v.b.r - v.a.r) / v.range;
		out.g = v.a.g + (int)(p->_z - obj->z_average) * (v.b.g - v.a.g) / v.range;
		out.b = v.a.b + (int)(p->_z - obj->z_average) * (v.b.b - v.a.b) / v.range;
	}
	else 
	{
		v.range = obj->z_average - obj->z_min;
		printf("range: %d\n", v.range);
		printf("_z: %.1f\n", p->_z);
		out.r = v.a.r + (obj->z_average - p->_z) * (v.b.r - v.a.r) / v.range;
		out.g = v.a.g + (obj->z_average - p->_z) * (v.b.g - v.a.g) / v.range;
		out.b = v.a.b + (obj->z_average - p->_z) * (v.b.b - v.a.b) / v.range;
	}
	p->color = get_hex_from_rgb(out.r, out.g, out.b);
	printf("OUT: r-%d, g-%d, b-%d\n", out.r, out.g, out.b);
}

static float	get_z_average(t_obj3d *obj)
{
	float	out;
	int		i;

	out = 0.0;
	i = -1;
	while (++i < obj->len)
		out += obj->a[i]._z;
	return (out / obj->len);
}