/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:44:38 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/07 14:10:03 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

char	**split_argv(char *argv[], int *argc)
{
	char	**fake_argv;
	int		i;
	int		j;

	fake_argv = ft_split(argv[1], ' ');
	i = 0;
	j = 1;
	while (fake_argv[i])
	{
		argv[j] = fake_argv[i];
		i++;
		j++;
	}
	if (fake_argv[0] == NULL)
		error();
	*argc = j;
	argv[j] = NULL;
	return (argv);
}

void	ws(t_node **a, t_node **b)
{
	int	size_a;

	size_a = ft_lstsize_ps(*a);
	if (size_a == 2)
		sort_two(a);
	else if (size_a == 3)
		sort_three(a);
	else if (size_a == 4)
		sort_four(a, b);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argv[1][0] == '\0')
		error();
	else if (argc == 2 && ft_strchr(argv[1], ' '))
		argv = split_argv(argv, &argc);
	check_args(argv);
	a = stack_init(argc, argv);
	check_dup(a);
	rrotate_a(&a, 0);
	printf("\n");
	while (a != NULL)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
	printf("-\na\n");
	/* if (argc >= 2 && argc <= 5)
		ws(&a, &b);
	else if (argc == 6)
		sort_five(&a, &b);
	else
		sort_hundred(&a, &b); */
	free_list(&a, 0);
}
