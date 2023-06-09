/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:31 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/13 15:06:35 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_node	*create_node(int dt)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = dt;
	node->next = NULL;
	return (node);
}

int	check_position(t_node *list, int target)
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

int	ft_lstsize_ps(t_node *a)
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

t_node	*stack_init(char *argv[], int flag)
{
	t_node	*a;
	t_node	*head_a;
	int		i;

	i = 1;
	if (flag == 0)
		i = flag;
	a = NULL;
	head_a = NULL;
	a = create_node(ft_atoi_2(&head_a, argv[i]));
	i++;
	head_a = a;
	while (argv[i])
	{
		a->next = create_node(ft_atoi_2(&head_a, argv[i]));
		a = a->next;
		i++;
	}
	return (head_a);
}

void	free_list(t_node **lst, int i)
{
	t_node	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	if (i == 1)
		error();
}
