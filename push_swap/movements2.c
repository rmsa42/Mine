/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:19:18 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/29 15:22:20 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rotate_a(Node **a, int i)
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
	if (i != 1)
		ft_printf("ra\n");
}

void	rotate_b(Node **b, int i)
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
	if (i != 1)
		ft_printf("rb\n");
}

void	rrotate_a(Node **a, int i)
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
	if (i != 1)
		ft_printf("rra\n");
}

void	rrotate_b(Node **b, int i)
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
	if (i != 0)
		ft_printf("rrb\n");
}

void	rr(Node **a, Node **b)
{
	int i;

	i = 1;
	rotate_a(a, i);
	rotate_b(b, i);
	ft_printf("rr\n");
}
