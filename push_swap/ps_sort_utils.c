/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:20:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/20 16:29:49 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	min_t(Node *a)
{
	Node	*templ;
	int		min;

	templ = a;
	min = a->data;
	while (templ != NULL)
	{
		if (templ->data < min)
		{
			min = templ->data;
			templ = a;
		}
		templ = templ->next;
	}
	return (min);
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
