/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/02 14:40:06 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	check_allocation(void *ptr)
{
	if (ptr == NULL)
	{
		perror("Memory allocation failed");
		exit (EXIT_FAILURE);
	}
}

void	free_all(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	free(d->obj->a);
	free(d->obj);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	set_rgb_to_hex(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

void	get_rgb_from_hex(int hexValue, int *r, int *g, int *b)
{
    *r = (hexValue >> 16) & 0xFF;
    *g = (hexValue >> 8) & 0xFF;
    *b = hexValue & 0xFF;
}