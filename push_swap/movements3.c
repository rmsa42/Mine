/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:52:05 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/07 11:42:58 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rrr(t_node **a, t_node **b, int i)
{
	int	k;

	k = 1;
	rrotate_a(a, k);
	rrotate_b(b, k);
	if (i != 0)
		ft_printf("rrr\n");
}
