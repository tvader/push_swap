/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 23:03:16 by tvader            #+#    #+#             */
/*   Updated: 2021/08/25 18:13:59 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# define BS 102400
typedef struct s_s
{
	int			val;
	struct s_s	*next;
}				t_s;
int		check_args(int cnt, char **args);
void	clearing(t_s *a, t_s *b, int ret);
t_s		*creation(int new_value);
void	error(void);
void	execute(char *buf, t_s **a, t_s **b);
void	exec_com(char *com, t_s **a, t_s **b);
int		is_sorted(t_s *stack);
int		is_in_stack(t_s *a, int value);
int		main(int cnt, char **args);
int		oper_pa(t_s **head_a, t_s **head_b);
int		oper_pb(t_s **head_a, t_s **head_b);
int		oper_ra(t_s **head);
int		oper_rb(t_s **head);
int		oper_rr(t_s **a, t_s **b);
int		oper_rra(t_s **head);
int		oper_rrb(t_s **head);
int		oper_rrr(t_s **a, t_s **b);
int		oper_sa(t_s **head);
int		oper_sb(t_s **head);
int		oper_ss(t_s **a, t_s **b);
int		push_back(int new_value, t_s **stack_head);
void	print_current(t_s	*a_top, t_s *b_top);
t_s		*read_stack(int cnt, char **args);
#endif // !CHECKER_H
