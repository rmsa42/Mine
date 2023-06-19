/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:25:10 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/19 16:12:59 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

Node	*swap_a(Node *a)
{
	if (ft_lstsize_ps(a) <= 1)
		return (a);
	else
	{
		int	temp;

		temp = a->data;
		a->data = a->next->data;
		a->next->data = temp;
		return (a);
	}
}

Node	*swap_b(Node *b)
{
	if (ft_lstsize_ps(b) <= 1)
		return (b);
	else
	{
		int temp;
		
		temp = b->data;
		b->data = b->next->data;
		b->next->data = temp;
		return (b);
	}
}

Node	*push_b(Node **b, Node **a, int data_a)
{
	Node	*new = NULL;
	Node	*temp = NULL;
	
	if (a == NULL)
		return (NULL); /* Saber o que retornar */
	else
	{
		if (*b == NULL)
		{
			*b = create_node(data_a);
		}
		else
		{
			new = *b;
			new->next = create_node(data_a);
		}
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
}
