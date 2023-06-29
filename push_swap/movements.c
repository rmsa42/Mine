/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:25:10 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/29 15:36:16 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

Node	*swap_a(Node *a, int i)
{
	int	temp;

	temp = 0;
	if (ft_lstsize_ps(a) <= 1)
		return (a);
	else
	{
		temp = a->data;
		a->data = a->next->data;
		a->next->data = temp;
		if (i != 1)
			ft_printf("sa\n");
		return (a);
	}
}

Node	*swap_b(Node *b, int i)
{
	int	temp;

	temp = 0;
	if (ft_lstsize_ps(b) <= 1)
		return (b);
	else
	{
		temp = b->data;
		b->data = b->next->data;
		b->next->data = temp;
		if (i != 1)
			ft_printf("sb\n");
		return (b);
	}
}

void	ss(Node *a, Node *b)
{
	int i;

	i = 1;
	swap_a(a, i);
	swap_b(b, i);
	ft_printf("ss\n");
}

void	push_b(Node **b, Node **a, int data_a)
{
	Node	*new;
	Node	*temp;

	new = NULL;
	if (*b == NULL)
	{
		*b = create_node(data_a);
	}
	else
	{
		new = create_node(data_a);
		new->next = *b;
		*b = new;
	}
	temp = *a;
	*a = (*a)->next;
	free(temp);
	ft_printf("pb\n");
}

void	push_a(Node **b, Node **a, int data_b)
{
	Node	*new;
	Node	*temp;

	new = NULL;
	if (*a == NULL)
	{
		*a = create_node(data_b);
	}
	else
	{
		new = create_node(data_b);
		new->next = *a;
		*a = new;
	}
	temp = *b;
	*b = (*b)->next;
	free(temp);
	ft_printf("pa\n");
}
