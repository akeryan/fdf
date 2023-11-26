/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:58:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 06:50:13 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	translate(t_obj3d *obj)
{
	int	i;

	i = 0;
	while (i < obj->len)
	{
		obj->a[i].iso_x = obj->a[i].x + obj->dx;
		obj->a[i].iso_y = obj->a[i].y + obj->dy;
		i++;
	}
}