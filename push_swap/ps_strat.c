/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:10:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/29 15:12:44 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	cheaper_nbr(Node *b, int rotations_a, int rotations_b, int size_a)
{
	int size_b;
	int nbr_m = 0;
	
	size_b = ft_lstsize_ps(b);
	if (rotations_a > 0 && rotations_b > 0)
	{
		if ((rotations_a > size_a/2 && rotations_b > size_b/2) || (rotations_a > size_a/2 && size_b == 2))
		{
			if ((size_a - rotations_a) < (size_b - rotations_b))
				nbr_m = size_b - rotations_b;
			else if ((size_b - rotations_b) < (size_a - rotations_a))
				nbr_m = size_a - rotations_a;
			else
				nbr_m = size_a - rotations_a;
		}
		else if (rotations_a == rotations_b)
			nbr_m = rotations_a;
		else if (rotations_a > size_a/2 && rotations_b < size_b/2 && size_b != 2)
			nbr_m = (size_a - rotations_a) + rotations_b;
		else if (rotations_b > size_b/2 && rotations_a < size_a/2 && size_b != 2)
			nbr_m = (size_b - rotations_b) + rotations_a;
		else
		{
			if (rotations_a < rotations_b)
				nbr_m = rotations_b;
			else if (rotations_b < rotations_a)
				nbr_m = rotations_a;
			else
				nbr_m = rotations_a;
		}
	}
	else
	{
		if (rotations_a == 0)
		{
			if (rotations_b > size_b/2)
				nbr_m = (size_b - rotations_b);
			else
				nbr_m = rotations_b;
		}
		else if (rotations_b == 0)
		{
			if (rotations_a > size_b/2)
				nbr_m = (size_a - rotations_a);
			else
				nbr_m = rotations_a;
		}	
	}
	nbr_m++;
	return (nbr_m);
}

int	cheaper_nbr2(Node *b, int rotations_a, int rotations_b, int size_a)
{
	int size_b;
	int nbr_m = 0;
	
	size_b = ft_lstsize_ps(b);
	if (rotations_a > 0 && rotations_b > 0)
	{
		if ((rotations_a > size_a/2 && rotations_b > size_b/2) || (rotations_a > size_a/2 && size_b == 2))
		{
			if ((size_a - rotations_a) < (size_b - rotations_b))
				nbr_m = size_b - rotations_b;
			else if ((size_b - rotations_b) < (size_a - rotations_a))
				nbr_m = size_a - rotations_a;
			else
				nbr_m = size_a - rotations_a;
		}
		else if (rotations_a == rotations_b)
			nbr_m = rotations_a;
		else if ((rotations_a > size_a/2 && rotations_b < size_b/2) && size_b != 2)
			nbr_m = (size_a - rotations_a) + rotations_b;
		else if ((rotations_b > size_b/2 && rotations_a < size_a/2) && size_b != 2)
			nbr_m = (size_b - rotations_b) + rotations_a;
		else
		{
			if (rotations_a < rotations_b)
				nbr_m = rotations_b;
			else if (rotations_b < rotations_a)
				nbr_m = rotations_a;
			else
				nbr_m = rotations_a;
		}
	}
	else
	{
		if (rotations_a == 0)
		{
			if (rotations_b > size_b/2)
				nbr_m = (size_b - rotations_b);
			else
				nbr_m = rotations_b;
		}
		else if (rotations_b == 0)
		{
			if (rotations_a > size_a/2)
				nbr_m = (size_a - rotations_a);
			else
				nbr_m = rotations_a;
		}	
	}
	nbr_m++;
	return (nbr_m);
}

int	nbr2move(Node *a, Node *b, int **target)
{
	Node	*temp_a;
	Node	*temp_b;
	int	rotations_a;
	int	rotations_b;
	int	nbr2return;
	int moves;
	int size_a;
	int	cheaper;
	int	nbr;
	int targetf;

	temp_a = a;
	size_a = ft_lstsize_ps(a);
	rotations_a = 0;
	while (temp_a != NULL)
	{
		if (temp_a->data > max(b) || temp_a->data < min(b))
		{
			nbr = max(b);
			rotations_b = check_position(b, nbr);
			moves = cheaper_nbr(b, rotations_a, rotations_b, size_a);
			/* printf("%d\n", moves); */
		}
		else if (temp_a->data < max(b) && temp_a->data > min(b))
		{
			temp_b = b;
			nbr = min(b);
			while (temp_b != NULL)
			{
				if (temp_a->data > temp_b->data)
				{
					if (nbr < temp_b->data)
						nbr = temp_b->data;
				}
				temp_b = temp_b->next;
			}
			rotations_b = check_position(b, nbr);
			moves = cheaper_nbr2(b, rotations_a, rotations_b, size_a);
			/* printf("%d\n", moves); */
		}
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
