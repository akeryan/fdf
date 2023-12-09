/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:19:30 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/06 21:09:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_handler(int key, t_data *d)
{
	if (key == ESC)
		close_window();
	if (d->bonus_function_ptr)
		d->bonus_function_ptr(key, d);
	transform(d->obj);
	render(d);
	return (0);
}

int	close_window(void)
{
	exit(0);
	return (0);
}
