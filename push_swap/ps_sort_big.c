/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:14:34 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/30 16:53:05 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sorting_2(t_node **a, t_node **b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	int	size;
	int	nbr;
	int	position;
	int j;
	
	j = 0;
	temp_b = *b;
	while (*b != NULL)
	{
		temp_b = *b;
		temp_a = *a;
		size = ft_lstsize_ps(*a);
		if (temp_b->data > max(*a))
		{
			position = check_position(*a, min(*a));
			while ((*a)->data != min(*a))
			{
				if (position > size/2)
					rrotate_a(a, j);
				else
					rotate_a(a, j);
			}
			push_a(b, a, (*b)->data);
		}
		else if (temp_b->data < min(*a))
		{
			position = check_position(*a, min(*a));
			while ((*a)->data != min(*a))
			{
				if (position > size/2)
					rrotate_a(a, j);
				else
					rotate_a(a, j);
			}
			push_a(b, a, (*b)->data);
		}
		else if (temp_b->data < max(*a) && temp_b->data > min(*a))
		{
			temp_a = *a;
			nbr = max(*a);
			while (temp_a != NULL)
			{
				if ((nbr > temp_a->data && temp_a->data > temp_b->data))
					nbr = temp_a->data;
				temp_a = temp_a->next;
			}
			position = check_position(*a, nbr);
			while ((*a)->data != nbr)
			{
				if (position > size/2)
					rrotate_a(a, j);
				else
					rotate_a(a, j);
			}
			push_a(b, a, (*b)->data);
		}
	}
}

void	sort_nbr(t_node **a, t_node **b, int nbr2sort, int target)
{
	int j;
	int	rotations_a;
	int	rotations_b;
	int	size_a;
	int size_b;
	
	j = 0;
	size_a = ft_lstsize_ps(*a);
	size_b = ft_lstsize_ps(*b);
	rotations_a = check_position(*a, nbr2sort);
	rotations_b = check_position(*b, target);
	while ((*a)->data != nbr2sort && (*b)->data != target)
	{
		if (rotations_a > size_a/2 && rotations_b > size_b/2)
			rrr(a, b);
		else if (rotations_a < size_a/2 && rotations_b > size_b/2)
			rotate_a(a, j);
		else if (rotations_b < size_b/2 && rotations_a > size_a/2)
			rotate_b(b, j);
		else
			rr(a, b);
	}
	if ((*a)->data == nbr2sort && (*b)->data != target)
	{
		while ((*b)->data != target)
		{
			if (rotations_b > size_b/2)
				rrotate_b(b, j);
			else
				rotate_b(b, j);
		}
	}
	else if ((*b)->data == target && (*a)->data != nbr2sort)
	{
		while ((*a)->data != nbr2sort)
		{
			if (rotations_a > size_a/2)
				rrotate_a(a, j);
			else
				rotate_a(a, j);
		}
	}
	push_b(b, a, (*a)->data);
}

void	put_all_a(t_node **a)
{
	int	j;
	int	size;
	int	position;

	j = 0;
	position = check_position(*a, min(*a));
	size = ft_lstsize_ps(*a);
	while ((*a)->data != min(*a))
	{
		if (position > size/2)
			rrotate_a(a, j);
		else
			rotate_a(a, j);
	}
}

int	sort_hundred(t_node **a, t_node **b)
{
	int	size_a;
	int	nbr2sort;
	int *target;

	if (check_sort(*a) == 0)
		return (1);
	push_b(b, a, (*a)->data);
	push_b(b, a, (*a)->data);
	while (ft_lstsize_ps(*a) != 3)
	{
		size_a = ft_lstsize_ps(*a);
		nbr2sort = nbr2move(*a, *b, size_a, &target);
		sort_nbr(a, b, nbr2sort, *target);
	}
	sort_three(a);
	sorting_2(a, b);
	put_all_a(a);
	return (0);
}
