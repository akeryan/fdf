/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:58:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/26 10:18:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	translate(t_obj3d *obj)
{
	int	i;

	i = 0;
	while (i < obj->len)
	{
		obj->a[i].x = obj->a[i]._x + obj->dx;
		obj->a[i].y = obj->a[i]._y + obj->dy;
		i++;
	}
}