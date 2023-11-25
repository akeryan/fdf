/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:19:30 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/25 21:02:44 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_handler(int key, t_data *d)
{
	printf("%d\n", key);
	if (key == 53)
		close_window(key, d);
	else if (key == 89)
	{
		d->angle = -abs(d->angle);
		rotate(d->obj, d, 'x');
		render(d);
	}
	else if (key == 91)
	{
		d->angle = abs(d->angle);
		rotate(d->obj, d, 'x');
		render(d);
	}
	return (0);
}

int	close_window(int key, t_data *d)
{
	exit(0);
}

int	get_keycode(int key, t_data *d)
{
	printf("%d\n", key);
	return (0);
}