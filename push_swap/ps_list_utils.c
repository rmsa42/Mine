/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:31 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/28 12:51:24 by rumachad         ###   ########.fr       */
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

int	check_position(Node *list, int target)
{
	int	i;

	i = 0;
	while (list->data != target)
	{
		i++;
		list = list->next;
	}
	return (i);
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

Node	*stack_init(int argc, char *argv[])
{
	Node *a = NULL;
	Node *head_a = NULL;
	int i;

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
