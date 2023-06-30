/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:29:00 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/30 14:37:59 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	top_min(t_node **a, int j)
{
	if ((*a)->next->next->data < (*a)->next->data)
	{
		swap_a(*a, j);
		rotate_a(a, j);
	}
}

void	middle_min(t_node **a, int j)
{
	if ((*a)->data < (*a)->next->next->data)
		swap_a(*a, j);
	else
		rotate_a(a, j);
}

void	last_min(t_node **a, int j)
{
	if ((*a)->data < (*a)->next->data)
		rrotate_a(a, j);
	else
	{
		swap_a(*a, j);
		rrotate_a(a, j);
	}
}

void	sort_three(t_node **a)
{
	int	min_t;
	int	j;

	j = 0;
	min_t = min(*a);
	if ((*a)->data == min_t)
	{
		top_min(a, j);
	}
	if ((*a)->next->data == min_t)
	{
		middle_min(a, j);
	}
	if ((*a)->next->next->data == min_t)
	{
		last_min(a, j);
	}
}

void	sort_two(t_node **a)
{
	int	j;

	j = 0;
	if ((*a)->data > (*a)->next->data)
		swap_a(*a, j);
}
