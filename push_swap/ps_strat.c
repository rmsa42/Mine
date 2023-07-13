/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:10:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/13 16:03:08 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	min_max(t_node *b, int rotations_a, int size_a)
{
	int	rotations_b;
	int	size_b;
	int	target;

	target = max(b);
	size_b = ft_lstsize_ps(b);
	rotations_b = check_position(b, target);
	return (mv_calcs(rotations_a, rotations_b, size_a, size_b));
}

int	btw_min_max(t_node *b, int data_a, int rotations_a, int size_a)
{
	t_node	*temp_b;
	int		size_b;
	int		rotations_b;
	int		target;

	temp_b = b;
	target = min(b);
	size_b = ft_lstsize_ps(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->data)
		{
			if (target < temp_b->data)
				target = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	rotations_b = check_position(b, target);
	return (mv_calcs(rotations_a, rotations_b, size_a, size_b));
}

int	a_nbr2move(t_node *a, t_node *b, int size_a)
{
	t_node	*temp_a;
	int		rotations_a;
	int		nbr2move;
	int		moves;
	int		cheaper_nbr;

	cheaper_nbr = 0;
	temp_a = a;
	rotations_a = 0;
	while (temp_a != NULL)
	{
		if (temp_a->data > max(b) || temp_a->data < min(b))
			moves = min_max(b, rotations_a, size_a);
		else if (temp_a->data < max(b) && temp_a->data > min(b))
			moves = btw_min_max(b, temp_a->data, rotations_a, size_a);
		if (cheaper_nbr > moves || rotations_a == 0)
		{
			cheaper_nbr = moves;
			nbr2move = temp_a->data;
		}
		rotations_a++;
		temp_a = temp_a->next;
	}
	return (nbr2move);
}

int	b_target(t_node *b, int data_a)
{
	t_node	*temp_b;
	int		target;

	temp_b = b;
	if (data_a > max(b) || data_a < min(b))
		return (max(b));
	else
		target = min(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->data)
		{
			if (target < temp_b->data)
				target = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	return (target);
}
