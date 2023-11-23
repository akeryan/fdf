/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:56:59 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/23 18:45:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "../fdf.h"

typedef struct s_line_vars
{
	t_pnt3d	*n;
	t_pnt3d	*w;
	int		x0;
	int		y0;
	int		dx;
	int		dy;
	int		i;
	int		d;
}	t_line_vars;

typedef struct s_plot_vars
{
	int	dx;
	int	dy;
	int	d;
	int	i;
}	t_plot_vars;

#endif