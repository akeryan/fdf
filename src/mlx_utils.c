/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/18 18:21:56 by akeryan          ###   ########.fr       */
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
int	**map_to_array(int fd)
{
	t_2dsize	*dim;
	int			**out;
	int			i;

	printf("HEERREE 1\n");
	dim = get_map_dimensions(fd);
	printf("HEERREE 2\n");
	out = new_2d_array(dim);
	printf("ARRAY MAPPING\n");
	map_to_arr(out, fd);
	return (out);
}

char **cpy_map_from_file(char *file)
{
	char	**map;
	char	*str;
	int		fd;
	int		cols;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	cols = get_num_of_columns(str);
	map = (char **)malloc(cols)
	//????????????????????????????
	
}

int	get_num_of_columns(char *str)
{
	int		len;

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

void	map_to_arr(int **arr, int fd)
{
	char	*line;
	int		row;
	int		col;

	row = -1;
	col = -1;
	while (42)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		row++;
		while (*line != '\0' && *line != '\n')
		{
			col++;
			while (*line == 32 || (*line >= 9 && *line <= 13))
				line++;
			if ((char)*line != '0')
				arr[row][col] = ft_atoi(line);
			while (ft_isdigit(*line))
				line++;
		}
	}
}

// dynamically creates a 2d-array of 'dim' dimansions filled with zerroes;
int **new_2d_array(t_2dsize *dim)
{
	int	**out;
	int	i;

	out = (int **)ft_calloc(dim->rows, sizeof(int *));
	if (out == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	i = 0;
	while (i < dim->rows)
	{
		out[i] = (int *)ft_calloc(dim->columns, sizeof(int));
		if (out[i] == NULL)
		{
			perror("Memory allocation failed");
			while (--i >= 0)
				free(out[i]);
			free(out);
			return (NULL);
		}
		i++;
	}
	return (out);
}

t_2dsize	*get_map_dimensions(int fd)
{
	t_2dsize	*size;

	size = (t_2dsize *)malloc(sizeof(t_2dsize));
	if (size == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	size->columns = get_num_of_columns(fd);
	size->rows = get_num_of_rows(fd);
	return (size);
}


int	get_num_of_rows(char fd)
{
	char	*str;
	int		len;	

	len = 0;
	while (42)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		else
			len++;
	}
	return (len);
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