/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/27 16:26:01 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char *argv[])
{
	t_data	d;
	int		fd;

	if (argc > 2 || !argv[1])
		exit (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Faild to open file");
		exit (0);
	}
	initialize(&d, argv[1]);
	put_obj_to_origin(d.obj);
	transform(d.obj, &d);
	render(&d);
	mlx_key_hook(d.win, key_handler, &d);
	mlx_hook(d.win, 17, 0, close_window, NULL);
	mlx_loop(d.mlx);
	return (0);
}
