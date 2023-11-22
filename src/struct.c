/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:14:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/22 17:32:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	*new_point(int x, int y)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
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