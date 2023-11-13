/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:09:32 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/13 11:09:34 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void check_ptr(void *ptr)
{
	if(ptr == NULL)
	{
		printf("ptr is NULL\n");
        exit(MLX_ERROR);
	}
}
void mlx_end(void *mlx_ptr, void *win_ptr)
{
    mlx_destroy_window(mlx_ptr, win_ptr);
    free(mlx_ptr);
}