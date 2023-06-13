/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:25:10 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/13 15:32:09 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

Node	*swap_a(Node *a)
{
	if (ft_lstsize_ps(a) <= 1)
		return (a);
	else
	{
		int	temp;

		temp = a->data;
		a->data = a->next->data;
		a->next->data = temp;
		return (a);
	}
}

Node	*swap_b(Node *b)
{
	if (ft_lstsize_ps(b) <= 1)
		return (b);
	else
	{
		int temp;
		
		temp = b->data;
		b->data = b->next->data;
		b->next->data = temp;
		return (b);
	}
}
