/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_five_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:29:43 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/22 13:15:04 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	top_five(Node **a, Node **b, int i)
{
	if (i == 0)
		push_b(b, a, (*a)->data);
	else if (i == 1)
	{
		rotate_a(a);
		push_b(b, a, (*a)->data);
	}
	else if (i == 2)
	{
		rotate_a(a);
		rotate_a(a);
		push_b(b, a, (*a)->data);
	}
	else if (i == 3)
	{
		rrotate_a(a);
		rrotate_a(a);
		push_b(b, a, (*a)->data);
	}
	else if (i == 4)
	{
		rrotate_a(a);
		push_b(b, a, (*a)->data);
	}
}

void	top_four(Node **a, Node **b, int i)
{
	if (i == 0)
		push_b(b, a, (*a)->data);
	else if (i == 1)
	{
		rotate_a(a);
		push_b(b, a, (*a)->data);
	}
	else if (i == 2)
	{
		rotate_a(a);
		rotate_a(a);
		push_b(b, a, (*a)->data);
	}
	else if (i == 3)
	{
		rrotate_a(a);
		push_b(b, a, (*a)->data);
	}
}

int	target(Node **a, int min)
{
	Node	*temp;
	int	i;

	i = 0;
	temp = *a;
	min = min_t(*a);
	while (temp->data != min)
	{
		i++;
		temp = temp->next;		
	}
	return (i);
}

int	sort_four(Node **a, Node **b)
{
	int	i;
	int	min;
	
	if (check(*a) == 0)
		return (0);
	min = 0;
	i = target(a, min);
	top_four(a, b, i);
	sort_three(a);
	push_a(b, a, (*b)->data);
	return (1);
}

int	sort_five(Node **a, Node **b)
{
	int		min;
	int		i;
	
	if (check(*a) == 0)
		return (0);
	min = 0;
	i = target(a, min);
	top_five(a, b, i);
	i = target(a, min);
	top_four(a, b, i);
	sort_three(a);
	push_a(b, a, (*b)->data);
	push_a(b, a, (*b)->data);
	return (1);
}