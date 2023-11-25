/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:34:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/25 08:37:28 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_obj(t_obj3d *obj, t_data *d)
{
	int	i;

	i = 0;
	while (i < obj->len)
	{
		if (obj->pts[i].w_ptr)
			plot_line(&obj->pts[i], obj->pts[i].w_ptr, d);
		if (obj->pts[i].n_ptr)
			plot_line(&obj->pts[i], obj->pts[i].n_ptr, d);
		i++;
	}
}