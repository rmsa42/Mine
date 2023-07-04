/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:14:34 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/04 17:01:51 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	put_in_position(t_node **a, t_node **b, int nbr2sort, int target)
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

void	sort1(t_node **b, int target, int rotations_b, int size_b)
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

void	sort4(t_node **a, int nbr2sort, int rotations_a, int size_a)
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

void	sort_nbr(t_node **a, t_node **b, int nbr2sort, int target)
{
	int	rotations_a;
	int	rotations_b;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize_ps(*a);
	size_b = ft_lstsize_ps(*b);
	rotations_a = check_position(*a, nbr2sort);
	rotations_b = check_position(*b, target);
	put_in_position(a, b, nbr2sort, target);
	if ((*a)->data == nbr2sort && (*b)->data != target)
		sort1(b, target, rotations_b, size_b);
	else if ((*b)->data == target && (*a)->data != nbr2sort)
		sort4(a, nbr2sort, rotations_a, size_a);
	push_b(b, a, (*a)->data);
}
