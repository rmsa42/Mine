/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/04 17:11:47 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ws(t_node **a, t_node **b)
{
	int	size_a;

	size_a = ft_lstsize_ps(*a);
	if (size_a == 2)
	{
		sort_two(a);
		free_list(a);
	}
	else if (size_a == 3)
	{
		sort_three(a);
		free_list(a);
	}
	else if (size_a == 4)
	{
		sort_four(a, b);
		free_list(a);
	}
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	check_args(argv);
	a = stack_init(argc, argv);
	check_dup(a);
	if (argc >= 2 && argc <= 5)
		ws(&a, &b);
	else if (argc == 6)
	{
		sort_five(&a, &b);
		free_list(&a);
	}
	else
	{
		sort_hundred(&a, &b);
		free_list(&a);
	}
}
