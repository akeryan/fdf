/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:19:30 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/02 18:17:14 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_handler(int key, t_data *d)
{
	if (key == XK_Escape)
		close_window(key, d);
	if (d->bonus_function_ptr)
		d->bonus_function_ptr(key, d);
	transform(d->obj, d);
	render(d);
	return (0);
}

int	close_window(int key, t_data *d)
{
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
}
