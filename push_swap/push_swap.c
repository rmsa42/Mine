/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/26 16:35:12 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	max(Node *list)
{
	int	max;
	
	max = list->data;
	while (list != NULL)
	{
		if (list->data > max)
			max = list->data;
		list = list->next;
	}
	return (max);
}

void	sort_hundred(Node **a, Node **b)
{
	Node	*temp_a;
	Node	*temp_b;
	int i = 0;
	int nbr_mv;
	
	if (i == 0)
	{	
		push_b(b, a, (*a)->data);
		push_b(b, a, (*a)->data);
		if ((*b)->data < (*b)->next->data)
			swap_b(*b);
		push_b(b, a, (*a)->data);
	}
	
}

int	main(int argc, char *argv[])
{
	Node *a = NULL;
	Node *b = NULL;
	

	a = stack_init(argc, argv);
	if (argc == 3)
		sort_two(&a);
	if (argc == 4)
		sort_three(&a);
	else if (argc == 5)
		sort_four(&a, &b);
	else if (argc == 6)
		sort_five(&a, &b);
	else
		sort_hundred(&a, &b);
	printf("\n");
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
	printf("-\nb\n\n");
}
