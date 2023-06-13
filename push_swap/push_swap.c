/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/13 15:36:19 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

Node *create_node(Node *head, int dt)
{
	Node *a;
	
	a = malloc(sizeof(Node));
	a->data = dt;
	a->next = head;
	return (a);
}

int	ft_lstsize_ps(Node *a)
{
	int	i;
	
	i = 0;
	if (a == NULL)
		return (0);
	else
	{
		while (a != NULL)
		{
			i++;
			a = a->next;
		}
		return (i);
	}
}

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

Node	*push_b(Node *a, Node *b)
{
	
}

int main(int argc, char *argv[])
{
	int i;
	Node *head = NULL;
	Node *b = NULL;

	i = 1;
	while (i < argc)
	{
		head = create_node(head, ft_atoi(argv[i]));
		i++;
	}
	swapA(head);
	while (head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

