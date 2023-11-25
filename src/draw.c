/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:34:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/25 17:36:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_obj(t_obj3d *obj, t_data *d)
{
	int	i;

	i = 0;
	while (i < obj->len)
	{
		if (obj->a[i].w_ptr)
		{
			//printf("%d: 1\n", i);
			//printf("x: %.1f, y: %.1f\n", obj->a[i].x, obj->a[i].y);
			//printf("n_x: %.1f, n_y: %.1f\n", obj->a[i].n_ptr->x, obj->a[i].n_ptr->y);
			plot_line(&obj->a[i], obj->a[i].w_ptr, d);
		}
		if (obj->a[i].n_ptr)
		{
			//printf("%d: 2\n", i);
			//printf("x: %.1f, y: %.1f\n", obj->a[i].x, obj->a[i].y);
			//printf("n_x: %.1f, n_y: %.1f\n", obj->a[i].n_ptr->x, obj->a[i].n_ptr->y);
			plot_line(&obj->a[i], obj->a[i].n_ptr, d);
			//printf("GGGGGG\n");
		}
		i++;
	} 
}