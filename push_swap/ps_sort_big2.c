/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:47:41 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/06 12:31:53 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	a_top(t_node **a, int nbr2sort, int rotations_a, int size_a)
{
	int	j;

	j = 0;
	while ((*a)->data != nbr2sort)
	{
		if (rotations_a > size_a / 2)
			rrotate_a(a, j);
		else
			rotate_a(a, j);
	}
}

void	b_top(t_node **b, int target, int rotations_b, int size_b)
{
	int	j;

	j = 0;
	while ((*b)->data != target)
	{
		if (rotations_b > size_b / 2)
			rrotate_b(b, j);
		else
			rotate_b(b, j);
	}
}

void	ab_top(t_node **a, t_node **b, int nbr2sort, int target)
{
	int	j;
	int	rotations_a;
	int	rotations_b;
	int	size_a;
	int	size_b;

	j = 0;
	size_a = ft_lstsize_ps(*a);
	size_b = ft_lstsize_ps(*b);
	rotations_a = check_position(*a, nbr2sort);
	rotations_b = check_position(*b, target);
	while ((*a)->data != nbr2sort && (*b)->data != target)
	{
		if (rotations_a > size_a / 2 && rotations_b > size_b / 2)
			rrr(a, b);
		else if (rotations_a < size_a / 2 && rotations_b > size_b / 2)
			rotate_a(a, j);
		else if (rotations_b < size_b / 2 && rotations_a > size_a / 2)
			rotate_b(b, j);
		else
			rr(a, b);
	}
}

void	sort(t_node **a, t_node **b, int nbr2sort, int target)
{
	int	rotations_a;
	int	rotations_b;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize_ps(*a);
	size_b = ft_lstsize_ps(*b);
	rotations_a = check_position(*a, nbr2sort);
	rotations_b = check_position(*b, target);
	ab_top(a, b, nbr2sort, target);
	if ((*a)->data == nbr2sort && (*b)->data != target)
		b_top(b, target, rotations_b, size_b);
	else if ((*b)->data == target && (*a)->data != nbr2sort)
		a_top(a, nbr2sort, rotations_a, size_a);
	push_b(b, a, 0);
}
