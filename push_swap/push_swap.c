/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/29 16:08:06 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"


int	check_dup(Node *a)
{
	Node *temp_a;
	Node *temp_a2;
	int i;
	int j;
	
	i = 0;
	temp_a = a;
	while (temp_a != NULL)
	{
		j = 0;
		temp_a2 = a;
		while (temp_a2 != NULL)
		{
			if ((temp_a2->data == temp_a->data) && (i != j))
			{
				write(2, "Error", 5);
				write(2, "\n", 1);	
				return (1);
			}
			j++;
			temp_a2 = temp_a2->next;
		}
		i++;
		temp_a = temp_a->next;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	Node *a = NULL;
	Node *b = NULL;
	
	a = stack_init(argc, argv);
	if (check_dup(a) == 1)
		return (0);
	if (argc == 1)
		return (0);
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
	/* printf("\n");
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
	printf("-\nb\n\n"); */
}
