/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:34:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 10:11:54 by akeryan          ###   ########.fr       */
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
			plot_line(&obj->a[i], obj->a[i].w_ptr, d);
		if (obj->a[i].n_ptr)
			plot_line(&obj->a[i], obj->a[i].n_ptr, d);
		i++;
	}
}
