/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:51:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/27 15:14:55 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_array	*array_from_map(t_lst *map)
{
	t_array	*a;
	t_node	*tmp;
	int		i;
	int		j;
	char	**spl;

	if (!map || !map->top)
		return (NULL);
	a = new_tarray(map->len, get_num_of_columns(map));
	if (!a)
		return (NULL);
	i = 0;
	tmp = map->top;
	while (42)
	{
		spl = ft_split(tmp->str, ' ');
		j = -1;
		while (++j < a->cols)
			a->arr[i][j] = ft_atoi(spl[j]);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
		i++;
	}	
	return (a);
}

t_lst	*read_map(char *file)
{
	t_lst	*lst;
	char	*str;
	int		fd;

	if (file == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Faild to open file");
		return (NULL);
	}
	lst = new_map();
	if (lst == NULL)
		return (NULL);
	while (42)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		push_bottom(lst, str);
	}
	close(fd);
	return (lst);
}

int	get_num_of_columns(t_lst *map)
{
	char	*str;
	int		len;

	if (map == NULL)
		return (-1);
	str = map->top->str;
	len = 0;
	while (*str != '\0' && *str != '\n')
	{
		while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		if (ft_isdigit(*str))
			len++;
		while (ft_isdigit(*str))
			str++;
	}
	return (len);
}

t_array	*new_tarray(int rows, int cols)
{
	t_array	*out;
	int		i;

	out = (t_array *)malloc(sizeof(t_array));
	if (out == NULL)
		return (NULL);
	out->arr = (int **)ft_calloc(rows, sizeof(int *));
	if (out->arr == NULL)
		return (NULL);
	out->cols = cols;
	out->rows = rows;
	i = 0;
	while (i < rows)
	{
		out->arr[i] = (int *)ft_calloc(cols, sizeof(int));
		if (out->arr[i] == NULL)
		{
			while (--i >= 0)
				free(out->arr[i]);
			free(out->arr);
			return (NULL);
		}
		i++;
	}
	return (out);
}
