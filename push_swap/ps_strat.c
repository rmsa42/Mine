/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:10:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/30 16:53:44 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	min_max(t_node *b, int *e_nbr, int rotations_a, int size_a)
{
	int	rotations_b;
	int	size_b;

	*e_nbr = max(b);
	size_b = ft_lstsize_ps(b);
	rotations_b = check_position(b, *e_nbr);
	return (cheaper_nbr(rotations_a, rotations_b, size_a, size_b));
}

int	btw_min_max(t_node *b, int *e_nbr, int data_a, int rotations_a, int size_a)
{
	t_node	*temp_b;
	int		size_b;
	int		rotations_b;

	temp_b = b;
	*e_nbr = min(b);
	size_b = ft_lstsize_ps(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->data)
		{
			if (*e_nbr < temp_b->data)
				*e_nbr = temp_b->data;
		}
		temp_b = temp_b->next;
	}
	rotations_b = check_position(b, *e_nbr);
	return (cheaper_nbr(rotations_a, rotations_b, size_a, size_b));
}

int	nbr2move(t_node *a, t_node *b, int size_a, int **target)
{
	t_node	*temp_a;
	int	rotations_a;
	int nbr2return;
	int	nbr;
	int moves;
	int	cheaper;
	int targetf;

	temp_a = a;
	rotations_a = 0;
	while (temp_a != NULL)
	{
		if (temp_a->data > max(b) || temp_a->data < min(b))
			moves = min_max(b, &nbr, rotations_a, size_a);
		else if (temp_a->data < max(b) && temp_a->data > min(b))
			moves = btw_min_max(b, &nbr, temp_a->data, rotations_a, size_a);
		if (cheaper > moves || rotations_a == 0)
		{
			cheaper = moves;
			nbr2return = temp_a->data;
			targetf = nbr;
			*target = &targetf;
		}
		rotations_a++;
		temp_a = temp_a->next;
	}
	return (nbr2return);
}
