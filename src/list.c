/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:41:45 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/21 13:51:12 by akeryan          ###   ########.fr       */
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

void	push_bottom(t_lst *lst, char *str)
{
	t_node	*new;
	t_node	*tmp;

	if (lst == NULL || str == NULL)
		return ;
	new = new_node();
	new->str = str;
	if (lst->top == NULL)
	{
		lst->top = new;
		lst->len++;
		return ;
	}
	tmp = lst->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	lst->len++;
}

void	free_list(t_lst *lst)
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

t_lst	*new_map(void)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (lst == NULL)
	{
		perror("Memory allocation failed in new_lst()");
		return (NULL);
	}
	lst->len = 0;
	lst->top = NULL;
	return (lst);
}

void	print_map(t_lst *lst)
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
