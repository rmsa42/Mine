/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:14:34 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/12 12:17:36 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rotating_a(t_node **a)
{
	int	size;
	int	position;

	position = check_position(*a, min(*a));
	size = ft_lstsize_ps(*a);
	while ((*a)->data != min(*a))
	{
		if (position > size / 2)
			rrotate_a(a, 0);
		else
			rotate_a(a, 0);
	}
}

void	sort_hundred(t_node **a, t_node **b)
{
	int	size_a;
	int	a_nbr2sort;
	int	b_nbr_target;

	if (check_sort(*a) == 0)
		return ;
	push_b(b, a, 0);
	push_b(b, a, 0);
	size_a = ft_lstsize_ps(*a);
	while (size_a > 3)
	{
		a_nbr2sort = a_nbr2move(*a, *b, size_a);
		b_nbr_target = b_target(*b, a_nbr2sort);
		sort(a, b, a_nbr2sort, b_nbr_target);
		size_a = ft_lstsize_ps(*a);
	}
	sort_three(a);
	sort2(a, b);
	rotating_a(a);
}
