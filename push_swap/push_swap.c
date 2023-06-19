/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/19 16:02:29 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

Node *create_node(int dt)
{
	Node *node;
	
	node = malloc(sizeof(Node));
	if (node == NULL)
		return (NULL);
	node->data = dt;
	node->next = NULL;
	return (node);
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

Node	*push_b(Node **b, Node **a, int data_a)
{
	Node	*new = NULL;
	Node	*temp = NULL;
	
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

int main(int argc, char *argv[])
{
	int i;
	Node *a = NULL;
	Node *head_a = NULL;
	Node *head_b = NULL;

	i = 1;
	a = create_node(ft_atoi(argv[i]));
	i++;
	head_a = a;
	while (i < argc)
	{
		a->next = create_node(ft_atoi(argv[i]));
		a = a->next;
		i++;
	}
	/* swap_a(head_a);
	swap_a(head_a); */
	push_b(&head_b, &head_a, head_a->data);
	push_b(&head_b, &head_a, head_a->data);
	swap_b(head_b);
	while (head_a != NULL)
	{
		printf("%d\n", head_a->data);
		head_a = head_a->next;
	}
	printf("-\na\n");
	while (head_b != NULL)
	{
		printf("%d\n", head_b->data);
		head_b = head_b->next;
	}
}

