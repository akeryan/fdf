/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:43 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/03 09:19:10 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	plot_line_low(t_p3d *a, t_p3d *b, t_data *d);
static void	plot_line_high(t_p3d *a, t_p3d *b, t_data *d);
static void	plot(int x, int y, t_data *d, int color);
static void plot_line_low_foo(t_plot_vars *q, t_p3d *a, t_p3d *b, t_data *d);
static void plot_line_high_foo(t_plot_vars *q, t_p3d *a, t_p3d *b, t_data *d);
static int	get_color(int a_hex, int b_hex, int steps, int step);

void	plot_line(t_p3d *a, t_p3d *b, t_data *d)
{
	if (fabsf(b->y - a->y) < fabsf(b->x - a->x))
	{
		if (a->x > b->x)
			plot_line_low(b, a, d);
		else
			plot_line_low(a, b, d);
	}
	else
	{
		if (a->y > b->y)
			plot_line_high(b, a, d);
		else
			plot_line_high(a, b, d);
	}
}

static void	plot_line_low(t_p3d *a, t_p3d *b, t_data *d)
{
	t_plot_vars	q;

	q.dx = b->x - a->x;
	q.dy = b->y - a->y;
	q.i = 1;
	if (q.dy < 0)
	{
		q.i = -1;
		q.dy = -q.dy;
	}
	q.d = 2 * q.dy - q.dx;
	q._x = a->x;
	q._y = a->y;
	plot_line_low_foo(&q, a, b, d);
}

static void plot_line_low_foo(t_plot_vars *q, t_p3d *a, t_p3d *b, t_data *d)
{
	while (q->_x <= b->x)
	{
		if (a->_z >= d->z_ave)
			q->color = get_color(b->color, a->color, b->x - a->x, q->_x);
		else
			q->color = get_color(a->color, b->color, b->x - a->x, q->_x);
		plot(q->_x, q->_y, d, q->color);
		if (q->d > 0)
		{
			q->_y = q->_y + q->i;
			q->d = q->d + (2 * (q->dy - q->dx));
		}
		else
			q->d = q->d + 2 * q->dy;
		q->_x++;
	}

}

static int	get_color(int a_hex, int b_hex, int steps, int step)
{
	t_rgb_color	a;
	t_rgb_color	b;
	t_rgb_color	out;
	float		ratio;

	ratio = (float)step / (steps - 1);
	out.r = a.r + ratio * (b.r - a.r);
	out.g = a.g + ratio * (b.g - a.g);
	out.b = a.b + ratio * (b.b - a.b);
	return (get_hex_from_rgb(out.r, out.g, out.b));
}

static void	plot_line_high(t_p3d *a, t_p3d *b, t_data *d)
{
	t_plot_vars	q;

	q.dx = b->x - a->x;
	q.dy = b->y - a->y;
	q.i = 1;
	if (q.dx < 0)
	{
		q.i = -1;
		q.dx = -q.dx;
	}
	q.d = 2 * q.dx - q.dy;
	q._x = a->x;
	q._y = a->y;
	plot_line_high_foo(&q, a, b, d);
}

static void plot_line_high_foo(t_plot_vars *q, t_p3d *a, t_p3d *b, t_data *d)
{
	while (q->_y <= b->y)
	{
		if (a->_z >= d->z_ave)
			q->color = get_color(b->color, a->color, b->x - a->x, q->_x);
		else
			q->color = get_color(a->color, b->color, b->x - a->x, q->_x);
		plot(q->_x, q->_y, d, q->color);
		if (q->d > 0)
		{
			q->_x = q->_x + q->i;
			q->d = q->d + (2 * (q->dx - q->dy));
		}
		else
			q->d = q->d + 2 * q->dx;
		q->_y++;
	}
}

static void	plot(int x, int y, t_data *d, int color)
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
