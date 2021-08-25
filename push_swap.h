/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:53:47 by tvader            #+#    #+#             */
/*   Updated: 2021/08/21 21:12:29 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
typedef struct s_s
{
	int			val;
	struct s_s	*next;
}				t_s;
int		calc_steps(int *m_a, int *m_b, int size_a, int size_b);
int		check_args(int cnt, char **args);
int		clearing(t_s *a, t_s *b, int ret);
t_s		*creation(int new_value);
void	error(void);
int		ft_abs(int num);
int		ind_of_min(int	*array, int size);
int		is_place(int value, t_s *stack, t_s *cur);
int		is_place_asc(int value, t_s *stack, t_s *cur);
int		is_sorted(t_s *stack);
int		is_sorted_comb(t_s *stack);
int		is_in_stack(t_s *a, int value);
int		little_sort(t_s **a, t_s **b);
int		makemoves(t_s **a_head, t_s **b_head, int a_move, int b_move);
int		main(int cnt, char **args);
int		main_sort(t_s **a, t_s **b);
int		max(int n1, int n2);
int		max_value(t_s *stack);
t_s		*min_element(t_s *stack);
int		min_value(t_s *stack);
int		moves_to_val(int value, t_s *stack);
int		oper_pa(t_s **head_a, t_s **head_b);
int		oper_pb(t_s **head_a, t_s **head_b);
int		oper_ra(t_s **head, int self, int *a_moves);
int		oper_rb(t_s **head, int self, int *b_moves);
int		oper_rr(t_s **a, t_s **b, int *a_moves, int *b_moves);
int		oper_rra(t_s **head, int self, int *a_moves);
int		oper_rrb(t_s **head, int self, int *b_moves);
int		oper_rrr(t_s **a, t_s **b, int *a_moves, int *b_moves);
int		oper_sa(t_s **head, int self);
int		oper_sb(t_s **head, int self);
int		oper_ss(t_s **a, t_s **b);
int		optimizer(int *vars, t_s **a);
int		push_back(int new_value, t_s **stack_head);
void	print_current(t_s	*a_top, t_s *b_top);
t_s		*read_stack(int cnt, char **args);
int		recomb(t_s **stack);
int		step_selection(t_s *a, t_s *b, int *cur_a, int *cur_b);
int		stack_size(t_s *stack);
t_s		*stack_last(t_s *lst);
int		where_to_ins(int value, t_s *stack);
int		where_to_ins_asc(int value, t_s *stack);
#endif // !PUSH_SWAP_H
