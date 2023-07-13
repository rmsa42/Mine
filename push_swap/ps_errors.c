/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:00:02 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/13 15:14:26 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_args(char *argv[], int flag)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (flag == 0)
		i = 0;
	while (argv[i])
	{
		k = 0;
		if (argv[i][k + 1] == '\0' && (argv[i][k] < '0' || argv[i][k] > '9'))
			error();
		while (argv[i][k] != '\0')
		{
			if (argv[i][0] == '0' && argv[i][1])
				error();
			if (argv[i][k] >= '0' && argv[i][k] <= '9')
				k++;
			else if (argv[i][0] == '-' && k == 0)
				k++;
			else
				error();
		}
		i++;
	}
}

void	check_dup(t_node *a)
{
	t_node	*head_a;
	t_node	*temp_a;

	head_a = a;
	while (a != NULL)
	{
		temp_a = a->next;
		while (temp_a != NULL)
		{
			if (temp_a->data == a->data)
				free_list(&head_a, 1);
			temp_a = temp_a->next;
		}
		a = a->next;
	}
}

int	ft_atoi_2(t_node **a, const char *str)
{
	int			i;
	long int	c;
	int			n;

	n = 1;
	c = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = (str[i] - '0') + (c * 10);
		i++;
	}
	if ((c * n) > 2147483647 || (c * n) < -2147483648)
		free_list(a, 1);
	return (c * n);
}
