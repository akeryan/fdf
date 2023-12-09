/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:43 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/06 16:19:56 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	plot_line_low(t_p3d *a, t_p3d *b, t_data *d);
static void	plot_line_high(t_p3d *a, t_p3d *b, t_data *d);
static void	plot_line_low_foo(t_plot_vars *q, t_p3d *a, t_p3d *b, t_data *d);
static void	plot_line_high_foo(t_plot_vars *q, t_p3d *a, t_p3d *b, t_data *d);

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

static void	plot_line_low_foo(t_plot_vars *q, t_p3d *a, t_p3d *b, t_data *d)
{
	while (q->_x <= b->x)
	{
		if (a->col == b->col)
		{
			q->color = a->col;
		}
		else
		{
			if (a->_z >= d->z_ave)
				q->color = get_color(a->col, b->col, b->x - a->x, q->_x - a->x);
			else
				q->color = get_color(a->col, b->col, b->x - a->x, q->_x - a->x);
		}
		plot(q->_x, q->_y, d, q->color);
		if (q->d > 0)
		{
			q->_y = q->_y + q->i;
			q->d = q->d + 2 * (q->dy - q->dx);
		}
		else
			q->d = q->d + 2 * q->dy;
		q->_x++;
	}
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

static void	plot_line_high_foo(t_plot_vars *q, t_p3d *a, t_p3d *b, t_data *d)
{
	while (q->_y <= b->y)
	{
		if (a->col == b->col)
		{
			q->color = a->col;
		}
		else
		{
			if (a->_z >= d->z_ave)
				q->color = get_color(a->col, b->col, b->x - a->x, q->_x - a->x);
			else
				q->color = get_color(a->col, b->col, b->x - a->x, q->_x - a->x);
		}
		plot(q->_x, q->_y, d, q->color);
		if (q->d > 0)
		{
			q->_x = q->_x + q->i;
			q->d = q->d + 2 * (q->dx - q->dy);
		}
		else
			q->d = q->d + 2 * q->dx;
		q->_y++;
	}
}
