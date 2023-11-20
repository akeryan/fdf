/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:41:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/20 16:31:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_node	*new_node(void)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	new->str = NULL;
	new->next = NULL;
	return (new);
}

void	push_bottom(t_map *lst, char *str)
{
	t_node	*new;
	t_node	*tmp;

	if (lst == NULL || str == NULL)
		return ;
	new = new_node();
	new->str = str;
	tmp = lst->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_list(t_map *lst)
{
	t_node	*current;
	t_node	*tmp;

	if (lst == NULL || lst->top == NULL)
		return ;
	current = lst->top;
	while (42)
	{
		tmp = current->next;
		free(current->str);
		free(current);
		if (tmp == NULL)
			break ;
		current = tmp;
	}
}

t_map	*new_lst(void)
{
	t_map	*lst;

	lst = (t_map *)malloc(sizeof(t_map));
	if (lst == NULL)
	{
		perror("Memory allocation failed in new_lst()");
		return (NULL);
	}
	lst->len = 0;
	lst->top = NULL;
	return (lst);
}

void	print_lst(t_map *lst)
{
	char	*str;
	t_node	*tmp;

	if (lst == NULL || lst->top == NULL)
		return ;
	tmp = lst->top;
	while (42)
	{
		printf("%s", tmp->str);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}

