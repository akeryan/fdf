/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:24:44 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/25 17:29:25 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	project(t_obj3d *obj)
{
	int		i;
	float	q;
	float	a;
	float	b;

	i = 0;
	q = sqrt(6);
	while (i < obj->len)
	{
		obj->a[i].iso_x = round(sqrt(2) / 2 * obj->a[i].x - sqrt(2) / 2 * obj->a[i].y);
		//if (obj->a[i].iso_x < 0)
			//obj->a[i].iso_x = 0;
		a = (1 / q) * obj->a[i].x + (1 / q);
		b = obj->a[i].y - (2 / q) * obj->a[i].z;
		obj->a[i].iso_y = round(a * b);
		//if (obj->a[i].iso_y < 0)
			//obj->a[i].iso_y = 0;

		//printf("%d = iso_x: %d, iso_y: %d\n", i, obj->a[i].iso_x, obj->a[i].iso_y);
		i++;
	}
}
