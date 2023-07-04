/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:11 by rumachad          #+#    #+#             */
/*   Updated: 2023/07/04 14:54:58 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct node
{
	int			data;
	struct node	*next;
}					t_node;

t_node	*stack_init(int argc, char *argv[]);
t_node	*create_node(int dt);
void	free_list(t_node **lst);
int		ft_atoi_2(const char *str);
void	check_args(char *argv[]);
void	check_dup(t_node *a);
int		check_sort(t_node *a);
void	error(void);
int		ft_lstsize_ps(t_node *a);
int		check_position(t_node *list, int target);
int		min(t_node *list);
int		max(t_node *list);
t_node	*swap_a(t_node *a, int i);
t_node	*swap_b(t_node *b, int i);
void	push_b(t_node **b, t_node **a, int data_a);
void	push_a(t_node **b, t_node **a, int data_b);
void	rotate_a(t_node **a, int i);
void	rotate_b(t_node **b, int i);
void	rrotate_a(t_node **a, int i);
void	rrotate_b(t_node **b, int i);
void	ss(t_node *a, t_node *b);
void	rr(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);
void	sort_two(t_node **a);
void	sort_three(t_node **a);
int		sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	sort_hundred(t_node **a, t_node **b);
void	sort_nbr(t_node **a, t_node **b, int nbr2sort, int target);
void	sorting_2(t_node **a, t_node **b);
int		nbr2move(t_node *a, t_node *b, int size_a);
int		b_nbr2top(t_node *b, int data_a);
int		cheaper_nbr(int rotations_a, int rotations_b, int size_a, int size_b);

#endif