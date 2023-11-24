/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:14:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/23 19:28:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	*new_point(int x, int y)
{
	t_pnt2d	*p;

	p = (t_pnt2d *)malloc(sizeof(t_pnt2d));
	if (!p)
	{
		perror("Memory allocation failed in new_point()");
		return (NULL);
	}
	p->x = x;
	p->y = y;
	return (p);
}

void	*new_pair(int x0, int y0, int x1, int y1)
{
	t_pair	*p;

	p = (t_pair *)malloc(sizeof(t_pair));
	if (!p)
	{
		perror("Memory allocation failed in new_pair()");
		return (NULL);
	}
	p->x0 = x0;
	p->x1 = x1;
	p->y0 = y0;
	p->y1 = y1;
	return (p);
}

t_p3d	*new_pnt3d(int x, int y, int z)
{
	t_p3d	*a;

	a = (t_p3d *)malloc(sizeof(t_p3d));
	if (a == NULL)
	{
		perror("Memory allocation faild in new_pnt3d()");
		return (NULL);
	}
	a->x = x;
	a->y = y;
	a->z = z;
	return (a);
}

