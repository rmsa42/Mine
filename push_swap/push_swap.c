/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/21 17:02:25 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_five(Node **a, Node **b)
{
	Node	*temp;
	int		i;
	
	temp = *a;
	i = 0;
	while (i < 2)
	{
		push_b(b, a, (*a)->data);
		temp = *a;
		i++;
	}
	sort_three(a);
}

int	main(int argc, char *argv[])
{
	Node *a = NULL;
	Node *b = NULL;
	

	a = stack_init(argc, argv);
	/* sort_two(&a);
	sort_three(&a); */
	sort_five(&a, &b);
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
	printf("-\nb\n");
}
