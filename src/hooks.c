/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:19:30 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/06 15:41:39 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_handler(int key, t_data *d)
{
	printf("%d\n", key);
	if (key == ESC)
		close_window(key, d);
	if (d->bonus_function_ptr)
		d->bonus_function_ptr(key, d);
	transform(d->obj, d);
	render(d);
	return (0);
}

int	close_window(int key, t_data *d)
{
	exit(0);
}
