/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:20:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/26 14:27:24 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	min_t(Node *list)
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

int	check(Node *a)
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
	if ((*a)->data > (*a)->next->data)
		swap_a(*a);
}

void	sort_three(Node **a)
{
	int	min;

	min = min_t(*a);
	if ((*a)->data == min)
	{
		if ((*a)->next->next->data < (*a)->next->data)
		{
			swap_a(*a);
			rotate_a(a);
		}
	}
	if ((*a)->next->data == min)
	{
		if ((*a)->data < (*a)->next->next->data)
			swap_a(*a);
		else
			rotate_a(a);
	}
	if ((*a)->next->next->data == min)
	{
		if ((*a)->data < (*a)->next->data)
			rrotate_a(a);
		else
		{
			swap_a(*a);
			rrotate_a(a);
		}
	}
}

/* int	sort(Node **a, Node **b)
{
	Node	*temp;
	int		min;
	int		min_s;
	int		i;

	if (*a == NULL)
		return (0);
	i = 1;
	temp = *a;
	min = (*a)->data;
	while (temp != NULL)
	{
		if (temp->data < min)
		{
			min = temp->data;
			temp = *a;
			min_s = i;
		}
		temp = temp->next;
		i++;
	}
	temp = *a;
	while (temp->data != min)
	{
		if (min_s < (i/2))
			rotate_a(a);
		else
			rrotate_a(a);
		temp = *a;
	}
	push_b(b, a, (*a)->data);
	sort(a, b);
	push_a(b, a, (*b)->data);
	return (1);
} */
