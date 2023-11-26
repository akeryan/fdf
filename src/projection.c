/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:24:44 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 10:15:46 by akeryan          ###   ########.fr       */
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
		obj->a[i].x = round(sqrt(2) / 2 * obj->a[i].x - sqrt(2) / 2 * obj->a[i].y);
		//if (obj->a[i].x < 0)
			//obj->a[i].x = 0;
		a = (1 / q) * obj->a[i].x + (1 / q);
		b = obj->a[i].y - (2 / q) * obj->a[i].z;
		obj->a[i].y = round(a * b);
		//if (obj->a[i].y < 0)
			//obj->a[i].y = 0;

		//printf("%d = x: %d, y: %d\n", i, obj->a[i].x, obj->a[i].y);
		i++;
	}
}
