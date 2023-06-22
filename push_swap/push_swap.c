/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/22 15:15:44 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_hundred(Node **a, Node **b)
{
	Node	*temp;
	int		target;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize_ps(*a);
	temp = *a;
	while (i != size/2)
	{
		target = temp->data;
		temp = temp->next;
		i++;
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
