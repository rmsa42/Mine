/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/13 16:07:31 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	free_array2d(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	which_sort(t_node **a, t_node **b)
{
	int	size_a;

	size_a = ft_lstsize_ps(*a);
	if (size_a == 2)
		sort_two(a);
	else if (size_a == 3)
		sort_three(a);
	else if (size_a == 4)
		sort_four(a, b);
	else if (size_a == 5)
		sort_five(a, b);
	else
		sort_hundred(a, b);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		flag;

	a = NULL;
	b = NULL;
	flag = 1;
	if (argc == 1)
		return (0);
	else if (argv[1][0] == '\0')
		error();
	else if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		argv = ft_split(argv[1], ' ');
		flag = 0;
	}
	check_args(argv, flag);
	a = stack_init(argv, flag);
	check_dup(a);
	if (argc >= 2)
		which_sort(&a, &b);
	if (flag == 0)
		free_array2d(argv);
	free_list(&a, 0);
}
