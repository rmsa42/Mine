/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:19:21 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/06 12:31:41 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_min_max(t_node **a, t_node **b, int size)
{
	int	position;
	int	j;

	j = 0;
	position = check_position(*a, min(*a));
	while ((*a)->data != min(*a))
	{
		if (position > size / 2)
			rrotate_a(a, j);
		else
			rotate_a(a, j);
	}
	push_a(b, a, 0);
}

void	sort_btw_min_max(t_node **a, t_node **b, int size)
{
	t_node	*temp_a;
	int		position;
	int		j;
	int		nbr;

	j = 0;
	nbr = max(*a);
	temp_a = *a;
	while (temp_a != NULL)
	{
		if ((nbr > temp_a->data && temp_a->data > (*b)->data))
			nbr = temp_a->data;
		temp_a = temp_a->next;
	}
	position = check_position(*a, nbr);
	while ((*a)->data != nbr)
	{
		if (position > size / 2)
			rrotate_a(a, j);
		else
			rotate_a(a, j);
	}
	push_a(b, a, 0);
}

void	sort2(t_node **a, t_node **b)
{
	int		size;

	while (*b != NULL)
	{
		size = ft_lstsize_ps(*a);
		if ((*b)->data > max(*a) || (*b)->data < min(*a))
			sort_min_max(a, b, size);
		else if ((*b)->data < max(*a) && (*b)->data > min(*a))
			sort_btw_min_max(a, b, size);
	}
}
