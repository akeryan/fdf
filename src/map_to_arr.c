/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:51:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/20 16:32:13 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*read_map(char *file)
{
	t_map	*lst;
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
	lst = new_lst();
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

//int	get_num_of_columns(t_lst *map)
//{
	//char 	*str;
	//int		len;

	//if (map == NULL)
		//return (-1);
	//str = map->str;
	//len = 0;
	//while (*str != '\0' && *str != '\n')
	//{
		//while (*str == 32 || (*str >= 9 && *str <= 13))
			//str++;
		//if (ft_isdigit(*str))
			//len++;
		//while (ft_isdigit(*str))
			//str++;
	//}
	//return (len);
//}

//int	get_num_of_rows(t_lst *map)
//{
	//int		num;

	//if (!map)	
		//return (-1);
	//num = 1;
	//while (map->next)
	//{
		//num++;
		//map = map->next;
	//}
	//return (num);
//}

//void	cpy_map_to_arr(int **arr, t_lst *map)
//{
	//char	*line;
	//int		row;
	//int		col;

	//if (!map)
		//return ;
	//row = -1;
	//col = -1;
	//while (map->str)
	//{
		//row++;
		//line = map->str;
		//while (*line != '\0' && *line != '\n')
		//{
			//col++;
			//while (*line == 32 || (*line >= 9 && *line <= 13))
				//line++;
			//if ((char)*line != '0')
				//arr[row][col] = ft_atoi(line);
			//while (ft_isdigit(*line))
				//line++;
		//}
		//map = map->next;
	//}
//}

//t_array	*new_2d_array(int rows, int cols)
//{
	//t_array	*out;
	//int		i;

	//out = (t_array *)malloc(sizeof(t_array));
	//if (out == NULL)
		//return (NULL);
	//out->arr = (int **)ft_calloc(rows, sizeof(int *));
	//if (out->arr == NULL)
		//return (NULL);
	//out->cols = cols;
	//out->rows = rows;
	//i = 0;
	//while (i < rows)
	//{
		//out->arr[i] = (int *)ft_calloc(cols, sizeof(int));
		//if (out->arr[i] == NULL)
		//{
			//while (--i >= 0)
				//free(out->arr[i]);
			//free(out->arr);
			//return (NULL);
		//}
		//i++;
	//}
	//return (out);
//}

//void	print_arr(t_array *a)
//{
	//int	i;
	//int	j;

	//i = 0;
	//j = 0;
	//while (i < a->rows)
	//{
		//while (j < a->cols)
		//{
			//printf("%d ", a->arr[i][j]);
			//j++;
		//}
		//printf("\n");
		//i++;
		//j = 0;
	//}
//}