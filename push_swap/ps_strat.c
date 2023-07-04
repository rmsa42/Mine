/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:10:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/04 15:59:44 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	min_max(t_node *b, int rotations_a, int size_a)
{
	int	rotations_b;
	int	size_b;
	int	nbr;

	nbr = max(b);
	size_b = ft_lstsize_ps(b);
	rotations_b = check_position(b, nbr);
	return (cheaper_nbr(rotations_a, rotations_b, size_a, size_b));
}

int	btw_min_max(t_node *b, int data_a, int rotations_a, int size_a)
{
	t_node	*temp_b;
	int		size_b;
	int		rotations_b;
	int		nbr;

	temp_b = b;
	nbr = min(b);
	size_b = ft_lstsize_ps(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->data)
		{
			if (nbr < temp_b->data)
				nbr = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	rotations_b = check_position(b, nbr);
	return (cheaper_nbr(rotations_a, rotations_b, size_a, size_b));
}

int	nbr2move(t_node *a, t_node *b, int size_a)
{
	t_node	*temp_a;
	int		rotations_a;
	int		nbr2return;
	int		moves;
	int		cheaper;

	temp_a = a;
	rotations_a = 0;
	while (temp_a != NULL)
	{
		if (temp_a->data > max(b) || temp_a->data < min(b))
			moves = min_max(b, rotations_a, size_a);
		else if (temp_a->data < max(b) && temp_a->data > min(b))
			moves = btw_min_max(b, temp_a->data, rotations_a, size_a);
		if (cheaper > moves || rotations_a == 0)
		{
			cheaper = moves;
			nbr2return = temp_a->data;
		}
		rotations_a++;
		temp_a = temp_a->next;
	}
	return (nbr2return);
}

int	b_nbr2top(t_node *b, int data_a)
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
