/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_junior.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:07:54 by tvader            #+#    #+#             */
/*   Updated: 2021/08/21 23:34:39 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	little_sort(t_s **a, t_s **b)
{
	int	a_moves;

	while (stack_size(*a) > 3)
		oper_pb(a, b);
	if (is_sorted_comb(*a) < 0)
		oper_sa(a, 1);
	while (*b)
	{
		a_moves = where_to_ins_asc((*b)->val, *a);
		makemoves(a, b, a_moves, 0);
		oper_pa(a, b);
	}
	return (recomb(a));
}

int	is_place_asc(int value, t_s *stack, t_s *cur)
{
	int	next;
	int	curval;

	if (!(cur->next))
	{
		next = stack->val;
		curval = cur->val;
	}
	else
	{
		next = cur->next->val;
		curval = cur->val;
	}
	if (curval == max_value(stack) && next == min_value(stack) && \
	stack_size(stack) > 2)
		return (0);
	if (value > curval && value < next)
		return (1);
	return (0);
}

int	where_to_ins_asc(int value, t_s *stack)
{
	int	moves;
	int	size;
	t_s	*cur;

	if (!stack || !(stack->next))
		return (0);
	moves = 1;
	size = stack_size(stack);
	cur = stack;
	if (value < min_value(stack))
		moves = moves_to_val(min_value(stack), stack);
	else if (value > max_value(stack))
		moves = moves_to_val(max_value(stack), stack) + 1;
	else
	{
		while (!is_place_asc(value, stack, cur))
		{
			cur = cur->next;
			moves++;
		}
	}
	if (moves <= stack_size(stack) / 2)
		return (moves);
	else
		return (moves - stack_size(stack));
}
