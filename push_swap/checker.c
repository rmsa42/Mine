/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:04:23 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/13 15:45:12 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	check_moves_2(t_node **a, t_node **b, char *line)
{
	if (line[2] == '\n')
		rr(a, b, 0);
	else if (line[2] == 'a' && line[3] == '\n')
		rrotate_a(a, 1);
	else if (line[2] == 'b' && line[3] == '\n')
		rrotate_b(b, 1);
	else if (line[2] == 'r' && line[3] == '\n')
		rrr(a, b, 0);
}

void	check_moves(t_node **a, t_node **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap_a(*a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap_b(*b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(*a, *b, 0);
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

void	free_array2d(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
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
	read_move(&a, &b);
	if (flag == 0)
		free_array2d(argv);
	free_list(&a, 0);
}
