/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:52:05 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/30 14:38:46 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rrr(t_node **a, t_node **b)
{
	int	i;

	i = 1;
	rrotate_a(a, i);
	rrotate_b(b, i);
	ft_printf("rrr\n");
}
