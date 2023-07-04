/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:47:41 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/04 17:05:58 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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
		if (position > size / 2)
			rrotate_a(a, j);
		else
			rotate_a(a, j);
	}
}

void	sort_hundred(t_node **a, t_node **b)
{
	int	size_a;
	int	nbr2sort;
	int	target;

	if (check_sort(*a) == 0)
		exit(1);
	push_b(b, a, (*a)->data);
	push_b(b, a, (*a)->data);
	size_a = ft_lstsize_ps(*a);
	while (size_a > 4)
	{
		size_a = ft_lstsize_ps(*a);
		nbr2sort = nbr2move(*a, *b, size_a);
		target = b_nbr2top(*b, nbr2sort);
		sort_nbr(a, b, nbr2sort, target);
	}
	sort_three(a);
	sorting_2(a, b);
	put_all_a(a);
}
