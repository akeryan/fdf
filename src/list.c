/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:41:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/19 19:01:15 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_str	*new_node(void)
{
	t_str	*new;

	new = (t_str *)malloc(sizeof(t_str));
	if (new == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	new->str = NULL;
	new->next = NULL;
	return (new);
}

t_str	*push_top(t_str *top, char *str)
{
	t_str	*new;

	new = new_node();
	new->str = ft_strdup(str);
	new->next = top;
	return (new);
}

t_str	*push_bottom(t_str *top, char *str)
{
	t_str	*new;
	t_str	*tmp;

	new = new_node();
	new->str = str;
	if (top == NULL)
		return (new);
	tmp = top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;	
	return (top);
}

void	free_list(t_str *top)
{
	t_str	*temp;
	t_str	*current;

	current = top;
	while (42)
	{
		temp = current->next;
		free(current->str);
		free(current);
		if (temp == NULL)
			break ;
		current = temp;
	}
}

