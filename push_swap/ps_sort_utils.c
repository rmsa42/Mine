/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:20:08 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/30 14:37:52 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	max(t_node *list)
{
	int	max;

	max = list->data;
	while (list != NULL)
	{
		if (list->data > max)
			max = list->data;
		list = list->next;
	}
	return (max);
}

int	min(t_node *list)
{
	int	min;

	min = list->data;
	while (list != NULL)
	{
		if (list->data < min)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int	check_sort(t_node *a)
{
	while ((a->data <= a->next->data) && a != NULL)
	{
		a = a->next;
		if (a->next == NULL)
			break ;
	}
	if (a->next == NULL)
		return (0);
	else
		return (1);
}
