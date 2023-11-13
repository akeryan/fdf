/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:50 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/13 11:19:19 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;

	//mlx_start(mlx_ptr, win_ptr);
    mlx_ptr = mlx_init();
	if(mlx_ptr == NULL)
	{
		printf("ptr is NULL\n");
        exit(MLX_ERROR);
	}

    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if(win_ptr == NULL)
	{
		printf("ptr is NULL\n");
        exit(MLX_ERROR);
	}

	mlx_loop(mlx_ptr);
	mlx_end(mlx_ptr, win_ptr);
}