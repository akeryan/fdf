/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:48:02 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 10:55:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	rotate_x(t_obj3d *obj, float *rad);
static void	rotate_y(t_obj3d *obj, float *rad);
static void	rotate_z(t_obj3d *obj, float *rad);

void	rotate(t_obj3d *obj, t_data *d, char axis)
{

	if (axis == 'x' || axis == 'X')
		rotate_x(obj, &d->_rad);
	else if (axis == 'y' || axis == 'Y')
		rotate_y(obj, &d->_rad);
	else if (axis == 'z' || axis == 'Z')
		rotate_z(obj, &d->_rad);
}

static void	rotate_x(t_obj3d *obj, float *rad)
{
	int	i;

	i = 0;
	while (i < obj->len)
	{
		obj->a[i].y = cos(*rad) * obj->a[i].y - sin(*rad) * obj->a[i].z;
		obj->a[i].z = sin(*rad) * obj->a[i].y + cos(*rad) * obj->a[i].z;
		i++;
	}
}

static void	rotate_y(t_obj3d *obj, float *rad)
{
	int	i;

	i = 0;
	while (i < obj->len)
	{
		obj->a[i].x = cos(*rad) * obj->a[i].x + sin(*rad) * obj->a[i].z;
		obj->a[i].z = -sin(*rad) * obj->a[i].x + cos(*rad) * obj->a[i].z;
		i++;
	}
}

static void	rotate_z(t_obj3d *obj, float *rad)
{
	int	i;

	i = 0;
	while (i < obj->len)
	{
		obj->a[i].x = cos(*rad) * obj->a[i].x - sin(*rad) * obj->a[i].y;
		obj->a[i].y = sin(*rad) * obj->a[i].x + cos(*rad) * obj->a[i].y;
		i++;
	}
}