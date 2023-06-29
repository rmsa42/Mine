/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:52:05 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/29 14:22:02 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	rrr(Node **a, Node **b)
{
	int i;
	
	i = 1;
	rrotate_a(a, i);
	rrotate_b(b, i);
	ft_printf("rrr\n");
}