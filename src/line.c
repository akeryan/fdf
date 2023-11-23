/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:43 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/23 15:42:44 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	plot_line(t_pair *p, t_data *d)
{
	t_pair	*tmp;

	tmp = new_pair(p->x1, p->y1, p->x0, p->y0);
	if (abs(p->y1 - p->y0) < abs(p->x1 - p->x0))
	{
		if (p->x0 > p->x1)
			plot_line_low(tmp, d);
		else
			plot_line_low(p, d);
	}
	else
	{
		if (p->y0 > p->y1)
			plot_line_high(tmp, d);
		else
			plot_line_high(p, d);
	}
}

static void	plot_line_low(t_pair *p, t_data *d)
{
	t_pnt2d	*a;	
	t_quad	q;

	q.dx = p->x1 - p->x0;
	q.dy = p->y1 - p->y0;
	q.i = 1;
	if (q.dy < 0)
	{
		q.i = -1;
		q.dy = -q.dy;
	}
	q.d = 2 * q.dy - q.dx;
	a = new_point(p->x0, p->y0);
	loop(p, &q, d, a);
	free(a);
}

static void	loop_low(t_pair *p, t_quad *q, t_data *d, t_pnt2d *a)
{
	while (a->x <= p->x1)
	{
		plot(a->x, a->y, d);
		if (q->d > 0)
		{
			a->y = a->y + q->i;
			q->d = q->d + (2 * (q->dy - q->dx));
		}
		else
			q->d = q->d + 2 * q->dy;
		a->x++;
	}
}

static void	plot_line_high(t_pair *p, t_data *d)
{
	t_pnt2d	*a;	
	t_quad	q;

	q.dx = p->x1 - p->x0;
	q.dy = p->y1 - p->y0;
	q.i = 1;
	if (q.dx < 0)
	{
		q.i = -1;
		q.dx = -q.dx;
	}
	q.d = 2 * q.dx - q.dy;
	a = new_point(p->x0, p->y0);
	loop_high(p, &q, d, a);
	free(a);
}

static void	loop_high(t_pair *p, t_quad *q, t_data *d, t_pnt2d *a)
{
	while (a->y <= p->y1)
	{
		plot(a->x, a->y, d);
		if (q->d > 0)
		{
			a->x = a->x + q->i;
			q->d = q->d + (2 * (q->dx - q->dy));
		}
		else
			q->d = q->d + 2 * q->dx;
		a->y++;
	}
}

static void	plot(int x, int y, t_data *d)
{
	int	pix;
	int	color;

	color = 0xFF0000;
	pix = (y * d->line_bytes) + (x * 4);
	if (d->endian == 1)
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
