/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:18:28 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/23 19:28:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	put_values(t_p3d *a, int x, int y, int z);

t_obj3d	*new_obj3d(int rows, int cols)
{
	t_obj3d	*out;
	int		i;

	out = (t_obj3d *)malloc(sizeof(t_obj3d));
	if (out == NULL)
		return (NULL);
	out->pts = (t_p3d **)malloc(rows * sizeof(t_p3d *));
	if (out->pts == NULL)
		return (NULL);
	out->rows = rows;
	out->cols = cols;
	i = 0;
	while (i < rows)
	{
		out->pts[i] = (t_p3d *)malloc(cols * sizeof(t_p3d));
		if (out->pts[i] == NULL)
		{
			while (--i >= 0)
				free(out->pts[i]);
			free(out->pts);
			return (NULL);
		}
		i++;
	}
	return (out);
}

t_obj3d	*obj_from_map(t_lst *map)
{
	t_obj3d	*a;
	t_node	*tmp;
	int		i;
	int		j;
	char	**spl;

	if (!map || !map->top)
		return (NULL);
	a = new_obj3d(map->len, get_num_of_columns(map));
	if (!a)
		return (NULL);
	i = 0;
	tmp = map->top;
	while (42)
	{
		spl = ft_split(tmp->str, ' ');
		j = -1;
		while (++j < a->cols)
			put_values(&a->pts[i][j], i, j, ft_atoi(spl[j]));
		if (!tmp->next)
			break ;
		tmp = tmp->next;
		i++;
	}	
	return (a);
}

static void	put_values(t_p3d *a, int x, int y, int z)
{
	if (a == NULL)
		return ;
	a->x = x;
	a->y = y;
	a->z = z;
}

void	print_obj(t_obj3d *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a->rows)
	{
		j = -1;
		while (++j < a->cols)
			printf("%.0f ", a->pts[i][j].z);
		printf("\n");
	}
}