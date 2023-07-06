/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:00:02 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/06 16:37:17 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_args(char *argv[])
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if ((argv[i][k] >= '0' && argv[i][k] <= '9') || argv[i][k] == '-')
				k++;
			else
				error();
		}
		i++;
	}
}

void	check_dup(t_node *a)
{
	t_node	*temp_a;
	t_node	*temp_a2;
	int		i;
	int		j;

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
				free_list(&a);
				error();
			}
			j++;
			temp_a2 = temp_a2->next;
		}
		i++;
		temp_a = temp_a->next;
	}
}

int	ft_atoi_2(const char *str)
{
	int			i;
	long int	c;
	int			a;

	a = 1;
	c = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a = a * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = (str[i] - '0') + (c * 10);
		i++;
	}
	if ((c * a) > 2147483647 || (c * a) < -2147483648)
		return (c);
	return (c * a);
}
