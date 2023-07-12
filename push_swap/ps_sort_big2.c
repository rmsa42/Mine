/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:47:41 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/12 12:01:48 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	a_top(t_node **a, int nbr2sort)
{
	int	rotations_a;
	int	size_a;

	size_a = ft_lstsize_ps(*a);
	rotations_a = check_position(*a, nbr2sort);
	while ((*a)->data != nbr2sort)
	{
		if (rotations_a > size_a / 2)
			rrotate_a(a, 0);
		else
			rotate_a(a, 0);
	}
}

void	b_top(t_node **b, int target)
{
	int	rotations_b;
	int	size_b;

	size_b = ft_lstsize_ps(*b);
	rotations_b = check_position(*b, target);
	while ((*b)->data != target)
	{
		if (rotations_b > size_b / 2)
			rrotate_b(b, 0);
		else
			rotate_b(b, 0);
	}
}

void	ab_top(t_node **a, t_node **b, int nbr2sort, int target)
{
	int	rotations_a;
	int	rotations_b;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize_ps(*a);
	size_b = ft_lstsize_ps(*b);
	rotations_a = check_position(*a, nbr2sort);
	rotations_b = check_position(*b, target);
	while ((*a)->data != nbr2sort && (*b)->data != target)
	{
		if (rotations_a > size_a / 2 && rotations_b > size_b / 2)
			rrr(a, b, 1);
		else if (rotations_a < size_a / 2 && rotations_b > size_b / 2)
			rotate_a(a, 0);
		else if (rotations_b < size_b / 2 && rotations_a > size_a / 2)
			rotate_b(b, 0);
		else
			rr(a, b, 1);
	}
}

void	sort(t_node **a, t_node **b, int nbr2sort, int target)
{
	ab_top(a, b, nbr2sort, target);
	if ((*a)->data == nbr2sort && (*b)->data != target)
		b_top(b, target);
	else if ((*b)->data == target && (*a)->data != nbr2sort)
		a_top(a, nbr2sort);
	push_b(b, a, 0);
}
