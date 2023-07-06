/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:04:23 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/06 15:53:36 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	check_moves_2(t_node **a, t_node **b, char *line)
{
	if (line[2] == '\n')
		rr(a, b);
	else if (line[2] == 'a' && line[3] == '\n')
		rrotate_a(a, 1);
	else if (line[2] == 'b' && line[3] == '\n')
		rrotate_b(b, 1);
	else if (line[2] == 'r' && line[3] == '\n')
		rrr(a, b);
}

void	check_moves(t_node **a, t_node **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap_a(*a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap_b(*b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(*a, *b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push_a(b, a, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push_b(b, a, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate_a(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate_b(b, 1);
	else if (line[0] == 'r' && line[1] == 'r')
		check_moves_2(a, b, line);
	else
		error();
}

void	read_move(t_node **a, t_node **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_moves(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sort(*a) == 0 && *b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	*argc = j;
	argv[j] = NULL;
	return (argv);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2 && ft_strchr(argv[1], ' '))
		argv = split_argv(argv, &argc);
	check_args(argv);
	a = stack_init(argc, argv);
	check_dup(a);
	read_move(&a, &b);
	free_list(&a);
}
