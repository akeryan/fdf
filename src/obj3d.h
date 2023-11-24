/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:44:52 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/24 13:04:19 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ3D_H
# define OBJ3D_H

# include "../fdf.h"

typedef struct s_obj_vars
{
	t_obj3d	*obj;
	t_p3d	*to;
	t_node	*tn;
	char	**spl;
	int		rows;
	int		cols;
	int		i;
	int		j;

}	t_obj_vars;

#endif