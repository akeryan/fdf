/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:18:28 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/24 15:35:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	put_values(t_obj_vars *v);

t_obj3d	*new_obj3d(int len)
{
	t_obj3d	*obj;

	obj = (t_obj3d *)malloc(sizeof(t_obj3d));
	check_allocation(obj);
	obj->len = len;
	obj->pts = (t_p3d *)malloc(len * sizeof(t_p3d));
	check_allocation(obj->pts);
	return (obj);
}

t_obj3d	*obj_from_map(t_lst *map)
{
	t_obj_vars	v;	

	if (!map || !map->top)
		return (NULL);
	v.rows = map->len;
	v.cols = get_num_of_columns(map);
	v.obj = new_obj3d(v.rows * v.cols);
	v.i = 0;
	v.tn = map->top;
	while (1)
	{
		v.spl = ft_split(v.tn->str, ' ');
		v.j = -1;
		while (++v.j < v.cols)
			put_values(&v);
		if (!v.tn->next)
			break ;
		v.tn = v.tn->next;
		v.i++;
	}
	free_split(v.spl);
	return (v.obj);
}

static void	put_values(t_obj_vars *v)
{
	if (v == NULL)
		return ;
	v->to = &v->obj->pts[v->i * v->cols + v->j];
	v->to->x = v->i;
	v->to->y = v->j;
	v->to->z = ft_atoi(v->spl[v->j]);
}

void	print_obj(t_obj3d *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 11)
	{
		j = -1;
		while (++j < 19)
			printf("%.0f ", a->pts[i * 19 + j].z);
		printf("\n");
	}
}