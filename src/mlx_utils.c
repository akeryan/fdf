/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/17 16:30:05 by akeryan          ###   ########.fr       */
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

int **data_casting(int fd)
{
	char	*line;
	int		rows;
	int		cols;

}

t_2dsize	*get_map_dimensions(int fd)
{
	t_2dsize	*size;
	char		*line;
	int			rows;

	size = (t_2dsize *)malloc(sizeof(t_2dsize));
	line = get_next_line(fd);
	size->columns = num_of_numbers(line);
	size->rows = 0;
	while (42)
	{
		line = get_next_line(fd);
		if (line)
			size->rows++;
		else
			break ;
	}
	return (size);
}

int	num_of_numbers(char *str)
{
	int	num;

	num = 0;
	while (*str != '\0' && *str != '\n')
	{
		while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		if (ft_isdigit(*str++))
			num++;
		while (ft_isdigit(*str++))
			;
	}
	return (num);
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