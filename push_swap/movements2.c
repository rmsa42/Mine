/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:19:18 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/22 00:10:29 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rotate_a(Node **a)
{
	Node	*temp;
	Node	*head;

	if (a != NULL)
	{
		head = *a;
		temp = *a;
		while (temp->next != NULL)
			temp = temp->next;
		*a = head->next;
		temp->next = head;
		temp = temp->next;
		temp->next = NULL;
	}
	ft_printf("ra\n");
}

void	rotate_b(Node **b)
{
	Node	*temp;
	Node	*head;

	if (b != NULL)
	{
		head = *b;
		temp = *b;
		while (temp->next != NULL)
			temp = temp->next;
		*b = head->next;
		temp->next = head;
		temp = temp->next;
		temp->next = NULL;
	}
	ft_printf("rb\n");
}

void	rrotate_a(Node **a)
{
	Node	*temp;

	if (a != NULL)
	{
		temp = *a;
		while(temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *a;
		*a = temp->next;
		temp->next = NULL;
	}
	ft_printf("rra\n");
}

void	rrotate_b(Node **b)
{
	Node	*temp;

	if (b != NULL)
	{
		temp = *b;
		while(temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *b;
		*b = temp->next;
		temp->next = NULL;
	}
	ft_printf("rrb\n");
}

void	rr(Node **a, Node **b)
{
	rotate_a(a);
	rotate_b(b);
	ft_printf("rrr\n");
}
