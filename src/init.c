/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:37:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/04 15:45:51 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		set_z_min_max_ave(t_data *d);
static void		set_color(t_p3d *p, t_obj3d *obj, int a_hex, int b_hex);
static void		colorize(t_obj3d *obj);

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
	set_z_min_max_ave(d);
	colorize(d->obj);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->width, d->height, "FDF");
	d->img = NULL;
	d->bonus_function_ptr = NULL;
	if (BONUS)
		d->bonus_function_ptr = &bonus_key_handler;
}

static void	set_z_min_max_ave(t_data *d)
{
	float	min;
	float	max;
	float	ave;
	t_p3d	*a;
	int		i;

	i = 0;
	a = d->obj->a;
	min = a[0].z;
	max = a[0].z;
	ave = 0;
	while (++i < d->obj->len)
	{
		if (min > a[i].z)
			min = a[i].z;
		if (max < a[i].z)
			max = a[i].z;
		ave += a[i].z;
	}
	d->obj->z_max = max;
	d->obj->z_min = min;
	d->obj->z_average = ave / d->obj->len;
	d->z_ave = d->obj->z_average;
}

static void	colorize(t_obj3d *obj)
{
	int		i;

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
		t_rgb_color c;
		get_rgb_from_hex(obj->a[i].color, &c.r, &c.g, &c.b);
		i++;
	}
}

static void	set_color(t_p3d *p, t_obj3d *obj, int a_hex, int b_hex)
{
	t_gradient_vars	v;
	t_rgb_color		out;

	get_rgb_from_hex(a_hex, &v.a.r, &v.a.g, &v.a.b);
	get_rgb_from_hex(b_hex, &v.b.r, &v.b.g, &v.b.b);
	if (p->_z > obj->z_average)
	{
		v.range = obj->z_max - obj->z_average;
		int z_ave = p->_z - obj->z_average;
		float br_ar = v.b.r - v.a.r;
		int times = z_ave * br_ar;
		int div = times / v.range;
		out.r = v.a.r + (int)(p->_z - obj->z_average) * (v.b.r - v.a.r) / v.range;
		out.g = v.a.g + (int)(p->_z - obj->z_average) * (v.b.g - v.a.g) / v.range;
		out.b = v.a.b + (int)(p->_z - obj->z_average) * (v.b.b - v.a.b) / v.range;
	}
	else 
	{
		v.range = obj->z_average - obj->z_min;
		out.r = v.a.r + (obj->z_average - p->_z) * (v.b.r - v.a.r) / v.range;
		out.g = v.a.g + (obj->z_average - p->_z) * (v.b.g - v.a.g) / v.range;
		out.b = v.a.b + (obj->z_average - p->_z) * (v.b.b - v.a.b) / v.range;
	}
	p->color = get_hex_from_rgb(out.r, out.g, out.b);
}