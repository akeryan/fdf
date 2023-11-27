/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:51:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/27 15:55:36 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
