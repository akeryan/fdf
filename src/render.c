/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:21:54 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/27 14:21:23 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	render(t_data *d)
{
	if (!d->img)
	{
		d->img = mlx_new_image(d->mlx, d->width, d->height);
		d->buf = mlx_get_data_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endi);
		d->buf_size = d->height * d->l_bytes;
	}
	ft_bzero(d->buf, d->buf_size);
	draw_obj(d->obj, d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

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
