/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:20:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/29 15:35:14 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	max(Node *list)
{
	int	max;
	
	max = list->data;
	while (list != NULL)
	{
		if (list->data > max)
			max = list->data;
		list = list->next;
	}
	return (max);
}

int	min(Node *list)
{
	int	min;
	
	min = list->data;
	while (list != NULL)
	{
		if (list->data < min)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int	check_sort(Node *a)
{
	while ((a->data <= a->next->data) && a != NULL)
	{
		a = a->next;
		if (a->next == NULL)
			break;
	}
	if (a->next == NULL)
		return (0);
	else
		return (1);
}

void	sort_two(Node **a)
{
	int j;

	j = 0;
	if ((*a)->data > (*a)->next->data)
		swap_a(*a, j);
}

void	sort_three(Node **a)
{
	int	min_t;
	int j;
	
	j = 0;
	min_t = min(*a);
	if ((*a)->data == min_t)
	{
		if ((*a)->next->next->data < (*a)->next->data)
		{
			swap_a(*a, j);
			rotate_a(a, j);
		}
	}
	if ((*a)->next->data == min_t)
	{
		if ((*a)->data < (*a)->next->next->data)
			swap_a(*a, j);
		else
			rotate_a(a, j);
	}
	if ((*a)->next->next->data == min_t)
	{
		if ((*a)->data < (*a)->next->data)
			rrotate_a(a, j);
		else
		{
			swap_a(*a, j);
			rrotate_a(a, j);
		}
	}
}
