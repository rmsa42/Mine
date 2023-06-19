/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rui <rui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:11 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/19 16:09:51 by rui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct node
{
	int				data;
	struct node	*next;
}					Node;

int	ft_lstsize_ps(Node *a);
Node	*swap_a(Node *a);
Node	*swap_b(Node *b);
Node	*push_b(Node **b, Node **a, int data_a);

#endif