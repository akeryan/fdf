/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:06:44 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/09 15:54:41 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	args_checkup(int argc, char *argv[], int *fd);

int	main(int argc, char *argv[])
{
	t_data	d;
	int		fd;

	args_checkup(argc, argv, &fd);
	init(&d, argv[1]);
	put_obj_to_origin(d.obj);
	transform(d.obj);
	render(&d);
	mlx_key_hook(d.win, key_handler, &d);
	mlx_hook(d.win, 17, 0, close_window, NULL);
	mlx_loop(d.mlx);
	return (0);
}

static void	args_checkup(int argc, char *argv[], int *fd)
{
	if (argc == 1)
	{
		printf("There is nothing to process. Please pass valid argument\n");
		exit(0);
	}
	if (argc > 2)
	{
		printf("FDF can process only one map at a time\n");
		exit (0);
	}
	if (!argv[1])
	{
		printf("Argument file doesn't exist\n");
		exit(0);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		perror("Faild to open file");
		exit (0);
	}
}
