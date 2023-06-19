/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/20 00:51:04 by rui              ###   ########.fr       */
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
	
	if (a == NULL)
		return (NULL);
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
}

Node	*push_a(Node **b, Node **a, int data_b)
{
	Node	*new = NULL;
	Node	*temp = NULL;
	
	if (b == NULL)
		return (NULL);
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
}

Node	*stack_init(int argc, char *argv[])
{
	int i;
	Node *a = NULL;
	Node *head_a = NULL;

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
	return (head_a);
}

int main(int argc, char *argv[])
{
	Node *b = NULL;
	Node *a = NULL;
	
	a = stack_init(argc, argv);
	/* swap_a(a);
	swap_a(a); */
	push_b(&b, &a, a->data);
	push_b(&b, &a, a->data);
	/* swap_b(b);
	push_a(&b, &a, b->data); */
	while (a != NULL)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
	printf("-\na\n\n");
	while (b != NULL)
	{
		printf("%d\n", b->data);
		b = b->next;
	}
	printf("-\nb\n");
}

