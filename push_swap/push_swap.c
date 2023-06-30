/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/30 15:03:52 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"


int	check_dup(t_node *a)
{
	t_node *temp_a;
	t_node *temp_a2;
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
				write(2, "Error\n", 6);	
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

void	free_list(t_node **lst)
{
	t_node *temp;
	
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

int	main(int argc, char *argv[])
{
	t_node *a = NULL;
	t_node *b = NULL;
	
	a = stack_init(argc, argv);
	if (check_dup(a) == 1)
	{
		free_list(&a);
		return (0);
	}
	if (argc == 1)
		return (0);
	else if (argc == 3)
	{
		sort_two(&a);
		free_list(&a);
	}
	else if (argc == 4)
	{
		sort_three(&a);
		free_list(&a);
	}
	else if (argc == 5)
	{
		sort_four(&a, &b);
		free_list(&a);
	}
	else if (argc == 6)
	{
		sort_five(&a, &b);
		free_list(&a);
	}
	else
	{
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
		free_list(&a);
	}
}
