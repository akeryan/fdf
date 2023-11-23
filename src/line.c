/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:43 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/23 12:40:32 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	plot_line(t_pair *p, char *buf, t_idata id)
{
	t_pair	*tmp;

	tmp = new_pair(p->x1, p->y1, p->x0, p->y0);
	if (abs(p->y1 - p->y0) < abs(p->x1 - p->x0))
	{
		if (p->x0 > p->x1)
			plot_line_low(tmp, buf, id);
		else
			plot_line_low(p, buf, id);
	}
	else
	{
		if (p->y0 > p->y1)
			plot_line_high(tmp, buf, id);
		else
			plot_line_high(p, buf, id);
	}
}

void	plot_line_low(t_pair *p, char *buf, t_idata id)
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
	while (a->x <= p->x1)
	{
		plot(a->x, a->y, buf, id);
		if (q.d > 0)
		{
			a->y = a->y + q.i;
			q.d = q.d + (2 * (q.dy - q.dx));
		}
		else
			q.d = q.d + 2 * q.dy;
		a->x++;
	}
}

void	plot_line_high(t_pair *p, char *buf, t_idata id)
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
	while (a->y <= p->y1)
	{
		plot(a->x, a->y, buf, id);
		if (q.d > 0)
		{
			a->x = a->x + q.i;
			q.d = q.d + (2 * (q.dx - q.dy));
		}
		else
			q.d = q.d + 2 * q.dx;
		a->y++;
	}
}
