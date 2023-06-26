/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:11 by rumachad          #+#    #+#             */
/*   Updated: 2023/06/26 14:28:20 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct node
{
	int				data;
	struct node	*next;
}					Node;

int		ft_lstsize_ps(Node *a);
int		min_t(Node *list);
int		check(Node *a);
Node	*create_node(int dt);
Node	*stack_init(int argc, char *argv[]);
Node	*swap_a(Node *a);
Node	*swap_b(Node *b);
void	push_b(Node **b, Node **a, int data_a);
void	push_a(Node **b, Node **a, int data_b);
void	rotate_a(Node **a);
void	rotate_b(Node **b);
void	rrotate_a(Node **a);
void	rrotate_b(Node **b);
void	ss(Node *a, Node *b);
void	rr(Node **a, Node **b);
void	rrr(Node **a, Node **b);
void	sort_two(Node **a);
void	sort_three(Node **a);
int		sort_four(Node **a, Node **b);
int		sort_five(Node **a, Node **b);

#endif