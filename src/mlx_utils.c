/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/20 14:16:54 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	check_ptr(void *ptr)
{
	if (ptr == NULL)
	{
		printf("ptr is NULL\n");
		exit(MLX_ERROR);
	}
}

void	mlx_end(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
}

// dynamically creates a 2-dimensional array from .fdf file
//int	**map_to_array(int fd)
//{
	//t_2dsize	*dim;
	//int			**out;
	//int			i;

	//printf("HEERREE 1\n");
	//dim = get_map_dimensions(fd);
	//printf("HEERREE 2\n");
	//out = new_2d_array(dim);
	//printf("ARRAY MAPPING\n");
	//map_to_arr(out, fd);
	//return (out);
//}



//t_array	*map_to_array(t_lst *map)
//{
	//int	cols;
	//int	rows;
	//int	**arr;

	//cols = get_num_of_columns(map);
	//rows = get_num_of_rows(map);
	//printf("HERE");
	//arr = new_2d_array(rows, cols);
	//cpy_map_to_arr(arr, map);
	//return (arr);
//}









void	check_allocation(void *ptr)
{
	if (ptr == NULL)
	{
		perror("Memory allocation failed");
		exit (EXIT_FAILURE);
	}
}

void	colorize_pixel(char *buf, int pix, int color, t_idata i_d)
{
	if (i_d.endian == 1)
	{
		buf[pix + 0] = (color >> 24);
		buf[pix + 1] = (color >> 16) & 0xFF;
		buf[pix + 2] = (color >> 8) & 0xFF;
		buf[pix + 3] = (color) & 0xFF;
	}
	else if (i_d.endian == 0)
	{
		buf[pix + 0] = (color) & 0xFF;
		buf[pix + 1] = (color >> 8) & 0xFF;
		buf[pix + 2] = (color >> 16) & 0xFF;
		buf[pix + 3] = (color >> 24);
	}
}