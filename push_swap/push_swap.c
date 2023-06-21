/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/22 00:44:26 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	statements(Node **a, Node **b, Node *temp)
{

}

void	sort_five(Node **a, Node **b)
{
	Node	*temp;
	int		i;
	
	i = 0;
	while (i < 2)
	{
		push_b(b, a, (*a)->data);
		i++;
	}
	sort_three(a);
	temp = *a;
	statements(a, b, temp);
	i = 0;
	temp = *a;
}

int	main(int argc, char *argv[])
{
	Node *a = NULL;
	Node *b = NULL;
	

	a = stack_init(argc, argv);
	/* sort_two(&a); */
	/* sort_three(&a); */
	sort_five(&a, &b);
	printf("\n");
	while (a != NULL)
	{
		if (a != NULL)
		{
			printf("%d", a->data);
			a = a->next;
		}
		if (b != NULL)
		{
			printf("   %d", b->data);
			b = b->next;	
		}
		if (a == NULL)
			printf("\n-\na\n");
		printf("\n");
	}
}
