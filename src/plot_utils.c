/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:52:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/06 16:20:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

uint32_t	get_color(uint32_t a_hex, uint32_t b_hex, int steps, int step)
{
	t_rgb_color	a;
	t_rgb_color	b;
	t_rgb_color	out;
	float		ratio;

	get_rgb_from_hex(a_hex, &a.r, &a.g, &a.b);
	get_rgb_from_hex(b_hex, &b.r, &b.g, &b.b);
	ratio = (float)step / (steps - 1);
	out.r = a.r + ratio * (b.r - a.r);
	out.g = a.g + ratio * (b.g - a.g);
	out.b = a.b + ratio * (b.b - a.b);
	return (get_hex_from_rgb(out.r, out.g, out.b));
}

uint32_t	get_hex_from_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

void	get_rgb_from_hex(uint32_t hexValue, uint8_t *r, uint8_t *g, uint8_t *b)
{
	*r = (hexValue >> 16) & 0xFF;
	*g = (hexValue >> 8) & 0xFF;
	*b = hexValue & 0xFF;
}

void	plot(int x, int y, t_data *d, int color)
{
	int	pix;

	pix = (y * d->l_bytes) + (x * 4);
	if (x >= 0 && x * 4 < d->l_bytes && y >= 0 && pix < d->buf_size)
	{
		if (d->endi == 1)
		{
			d->buf[pix + 0] = (color >> 24);
			d->buf[pix + 1] = (color >> 16) & 0xFF;
			d->buf[pix + 2] = (color >> 8) & 0xFF;
			d->buf[pix + 3] = (color) & 0xFF;
		}
		else
		{
			d->buf[pix + 0] = (color) & 0xFF;
			d->buf[pix + 1] = (color >> 8) & 0xFF;
			d->buf[pix + 2] = (color >> 16) & 0xFF;
			d->buf[pix + 3] = (color >> 24);
		}
	}
}
